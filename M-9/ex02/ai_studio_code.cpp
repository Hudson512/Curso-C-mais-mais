#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <iomanip> // Para std::setprecision

// --- Funções Auxiliares Estáticas (Visíveis apenas neste arquivo) ---

// Gera o n-ésimo número de Jacobsthal: J_n = J_{n-1} + 2*J_{n-2}
// Sequência: 0, 1, 1, 3, 5, 11, 21, 43, ...
size_t getJacobsthal(size_t n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    size_t prev2 = 0;
    size_t prev1 = 1;
    size_t current = 0;
    
    for (size_t i = 2; i <= n; ++i) {
        current = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

// Implementação Template do Algoritmo Ford-Johnson
// Funciona tanto para std::vector quanto para std::deque
template <typename Container>
void runFordJohnson(Container& c) {
    size_t n = c.size();
    if (n <= 1) return; // Base da recursão

    // 1. Lidar com elemento sobrando (Straggler) se o tamanho for ímpar
    bool hasStraggler = false;
    int straggler = 0;
    if (n % 2 != 0) {
        hasStraggler = true;
        straggler = c.back();
        c.pop_back();
    }

    // 2. Criar Pares e separar Vencedores (maiores) e Perdedores (menores)
    // Usamos std::pair para manter a associação temporariamente
    std::vector<std::pair<int, int> > pairs;
    typename Container::iterator it = c.begin();
    while (it != c.end()) {
        int first = *it;
        it++;
        if (it == c.end()) break; // Segurança, não deve acontecer devido ao check de ímpar
        int second = *it;
        it++;

        if (first > second)
            pairs.push_back(std::make_pair(first, second));
        else
            pairs.push_back(std::make_pair(second, first));
    }

    // 3. Recursão: Ordenar os vencedores
    // Colocamos os vencedores em um container para a chamada recursiva
    Container mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
    }

    runFordJohnson(mainChain); // Chama recursivamente

    // 4. Inserção
    // Agora mainChain está ordenada: a1, a2, a3...
    // Precisamos reinserir os perdedores (b1, b2...) na mainChain.
    
    // Primeiro, reconstruímos a lista de pendentes (losers) alinhada com a mainChain ordenada.
    // Como os valores podem ser duplicados, precisamos ter cuidado ao achar o par correto.
    // Vamos criar uma lista 'pendings' onde pendings[i] é o par de mainChain[i].
    
    Container pendings;
    // Copia auxiliar de pairs para podermos remover itens já usados (caso haja duplicatas)
    std::vector<std::pair<int, int> > tempPairs = pairs;

    for (typename Container::iterator it = mainChain.begin(); it != mainChain.end(); ++it) {
        int winnerVal = *it;
        // Encontrar o perdedor correspondente em tempPairs
        for (size_t i = 0; i < tempPairs.size(); ++i) {
            if (tempPairs[i].first == winnerVal) {
                pendings.push_back(tempPairs[i].second);
                tempPairs.erase(tempPairs.begin() + i); // Remove para evitar reuso errado em duplicatas
                break;
            }
        }
    }

    // O primeiro elemento pendente (b1) é par do menor vencedor (a1).
    // Como a1 é o menor da mainChain, b1 é menor que a1, e logo menor que qualquer outro da chain.
    // Inserimos b1 no início.
    c.clear(); // Limpamos o container original para reconstruí-lo
    c.insert(c.begin(), pendings[0]);
    // Adicionamos a mainChain inteira de volta
    c.insert(c.end(), mainChain.begin(), mainChain.end());

    // Agora inserimos os restantes b's usando a sequência de Jacobsthal
    // Pendings[0] já foi. Restam índices 1, 2, 3...
    size_t n_pendings = pendings.size();
    size_t jacobIdx = 3; // O próximo número de Jacobsthal relevante é J_3 = 3
    size_t lastInsertedIndex = 0; // Índice do último elemento de 'pendings' inserido (já inserimos o 0)

    // Loop pelos grupos de Jacobsthal
    for (size_t k = 3; ; ++k) {
        size_t currentJacob = getJacobsthal(k);
        
        // Ajustar limite para não passar do tamanho
        size_t groupEnd = currentJacob;
        if (groupEnd >= n_pendings) groupEnd = n_pendings;

        // Inserir elementos do grupo atual na ordem inversa (ex: 3, 2)
        // O algoritmo diz para inserir b_i. Sabemos que b_i < a_i.
        // Portanto, a busca binária pode ser feita em toda a lista 'c' até onde a_i estiver.
        // Para simplificar (e como std::lower_bound é O(log n)), buscamos no container todo 'c',
        // o que garante a posição correta.
        
        for (size_t i = groupEnd - 1; i > lastInsertedIndex; --i) {
            int valToInsert = pendings[i];
            
            // Busca binária para encontrar posição
            typename Container::iterator pos = std::lower_bound(c.begin(), c.end(), valToInsert);
            c.insert(pos, valToInsert);
        }

        lastInsertedIndex = groupEnd - 1;
        if (groupEnd == n_pendings) break;
    }

    // 5. Reinserir o Straggler (se houver)
    if (hasStraggler) {
        typename Container::iterator pos = std::lower_bound(c.begin(), c.end(), straggler);
        c.insert(pos, straggler);
    }
}

// --- Métodos da Classe PmergeMe ---

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }

double PmergeMe::getTimeInUs(struct timeval start, struct timeval end) 
{
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    return (seconds * 1e6 + microseconds);
}

void PmergeMe::displayContainer(const std::string& prefix, const std::vector<int>& container) 
{
    std::cout << prefix;
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << " " << container[i];
    }
    std::cout << std::endl;
}

void PmergeMe::displayContainer(const std::string& prefix, const std::deque<int>& container) 
{
    std::cout << prefix;
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << " " << container[i];
    }
    std::cout << std::endl;
}

// Implementação real chamando o template
void PmergeMe::sortVector(std::vector<int>& vec) {
    runFordJohnson(vec);
}

// Implementação real chamando o template
void PmergeMe::sortDeque(std::deque<int>& deq) {
    runFordJohnson(deq);
}

void PmergeMe::process(int argc, char* argv[]) {
    std::vector<int> vec;
    std::deque<int> deq;
    struct timeval start, end;

    // 1. Parsing
    for (int i = 1; i < argc; ++i) {
        char* endptr;
        long value = std::strtol(argv[i], &endptr, 10);
        if (*endptr != '\0' || value < 0) { // Aceitando 0 ou positivo conforme enunciado, ajuste se for estritamente positivo
             std::cerr << "Error: Invalid input." << std::endl;
             // throw ou exit, dependendo das regras do subject. Aqui apenas return.
             return;
        }
        vec.push_back(static_cast<int>(value));
        deq.push_back(static_cast<int>(value));
    }

    // 2. Display Before
    displayContainer("Before:", vec);

    // 3. Vector Sort
    gettimeofday(&start, NULL);
    sortVector(vec);
    gettimeofday(&end, NULL);
    double timeVec = getTimeInUs(start, end);

    // 4. Deque Sort
    gettimeofday(&start, NULL);
    sortDeque(deq);
    gettimeofday(&end, NULL);
    double timeDeq = getTimeInUs(start, end);

    // 5. Display After
    displayContainer("After: ", vec);

    // 6. Tempos
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " 
              << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " 
              << timeDeq << " us" << std::endl;
}