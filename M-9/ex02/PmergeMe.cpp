/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:25:35 by hmateque          #+#    #+#             */
/*   Updated: 2025/12/08 16:33:24 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"

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

// Funções de display
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


// --- Placeholder para as funções de ordenação ---
// Você deve implementar o algoritmo de Ford-Johnson aqui.
// Esta é a parte complexa do exercício.

void PmergeMe::sortVector(std::vector<int>& vec) {
    // Implemente o algoritmo Ford-Johnson para std::vector aqui.
    // Exemplo Simples (Apenas para compilação inicial, NÃO é Ford-Johnson):
    std::sort(vec.begin(), vec.end()); 
}

void PmergeMe::sortDeque(std::deque<int>& deq) {
    // Implemente o algoritmo Ford-Johnson para std::deque aqui.
    // Exemplo Simples (Apenas para compilação inicial, NÃO é Ford-Johnson):
    std::sort(deq.begin(), deq.end());
}


// A função principal que gere o fluxo
void PmergeMe::process(int argc, char* argv[]) {
    std::vector<int> vec;
    std::deque<int> deq;
    struct timeval start, end;

    // 1. Parsing e Validação da Entrada
    for (int i = 1; i < argc; ++i) {
        char* endptr;
        long value = std::strtol(argv[i], &endptr, 10);

        if (*endptr != '\0' || value <= 0) {
            throw std::runtime_error("Invalid input (not a positive integer).");
        }
        
        // Verificação de duplicatas é opcional (a seu critério), mas recomendada
        // if (std::find(vec.begin(), vec.end(), value) != vec.end()) { /* throw error */ }

        vec.push_back(static_cast<int>(value));
        deq.push_back(static_cast<int>(value));
    }

    // 2. Display Before
    displayContainer("Before:", vec);

    // 3. Ordenação e Timing para std::vector
    gettimeofday(&start, NULL);
    sortVector(vec); // Chame sua implementação Ford-Johnson aqui
    gettimeofday(&end, NULL);
    double timeVec = getTimeInUs(start, end);

    // 4. Ordenação e Timing para std::deque
    gettimeofday(&start, NULL);
    sortDeque(deq); // Chame sua implementação Ford-Johnson aqui
    gettimeofday(&end, NULL);
    double timeDeq = getTimeInUs(start, end);

    // 5. Display After (pode usar qualquer um dos containers, já que devem ser iguais)
    displayContainer("After:", vec);

    // 6. Display Tempos
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " 
              << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " 
              << timeDeq << " us" << std::endl;
}
