Esta documentação detalha o funcionamento interno da função `runFordJohnson`. O objetivo é que você entenda a **lógica algorítmica** para ser capaz de explicar o código ou recriá-lo do zero.

---

# Documentação Técnica: Algoritmo Merge-Insertion (Ford-Johnson)

**Objetivo:** Ordenar uma coleção de números utilizando o mínimo possível de comparações.
**Estrutura:** Recursiva (Divide and Conquer).

---

## Fluxo Passo a Passo da Função

A função pode ser dividida em **5 Fases Principais**. Vamos analisar o que acontece em cada uma.

### Fase 1: Tratamento de Ímpares (The Straggler)
O algoritmo baseia-se em formar **pares**. Se o número de elementos ($N$) for ímpar, sobra um elemento que não pode ser emparelhado.

1.  **Verificação:** Se `size % 2 != 0`.
2.  **Ação:** Removemos o último elemento do container e o guardamos numa variável temporária (`straggler`).
3.  **Estado:** O container agora tem um número par de elementos e o `straggler` fica "esperando" até o final do processo.

### Fase 2: Emparelhamento e Seleção de Vencedores
Aqui reduzimos o problema pela metade ($N/2$).

1.  **Agrupamento:** Dividimos os elementos em pares disjuntos: $(e_1, e_2), (e_3, e_4), \dots$
2.  **Comparação:** Dentro de cada par, comparamos os valores.
    *   O maior valor é chamado de **Winner** ($a$).
    *   O menor valor é chamado de **Loser** ($b$).
3.  **Armazenamento:**
    *   Criamos uma lista apenas com os **Winners** (`mainChain`).
    *   Guardamos a relação "quem perdeu para quem" (geralmente usando um `std::vector<std::pair>`).

> **Nota:** Se tínhamos 10 elementos, agora temos uma lista de 5 Winners para ordenar recursivamente.

### Fase 3: Recursão (O núcleo do Merge)
Precisamos que a lista de vencedores esteja ordenada para que a lógica de inserção funcione.

1.  **Chamada Recursiva:** Chamamos `runFordJohnson(mainChain)`.
2.  **Condição de Parada:** Quando a lista tem 1 ou 0 elementos, a recursão para.
3.  **Retorno:** A função retorna e agora temos a `mainChain` perfeitamente ordenada: $a_1 < a_2 < a_3 < \dots < a_n$.

### Fase 4: Reconstrução e Mapeamento
Ao voltar da recursão, temos os Winners ordenados ($a_1, a_2...$), mas precisamos saber quem eram seus respectivos Losers ($b_1, b_2...$).

1.  **Mapeamento:** Percorremos a `mainChain` ordenada. Para cada elemento $a_i$, buscamos na nossa lista de pares quem era o $b_i$ associado.
2.  **Lista `pendings`:** Criamos uma lista de elementos pendentes (os Losers) que agora estão indexados de acordo com a ordem dos seus Winners.
    *   $b_1$ é o perdedor correspondente a $a_1$ (o menor vencedor).
    *   $b_2$ é o perdedor correspondente a $a_2$.

### Fase 5: Inserção Otimizada (O "Pulo do Gato")
Esta é a parte complexa que dá nome ao algoritmo. Inserimos os Losers ($b$) na `mainChain` ($a$).

#### 5.1. A Inserção Gratuita ($b_1$)
*   Sabemos que $b_1 < a_1$.
*   Como $a_1$ é o menor elemento da cadeia principal, $b_1$ é **menor que todos**.
*   **Ação:** Inserimos $b_1$ no início da `mainChain` sem fazer nenhuma comparação.
*   **Cadeia Atual:** `[b1, a1, a2, a3...]`.

#### 5.2. Sequência de Jacobsthal
Para os restantes perdedores ($b_2, b_3, \dots$), não inserimos na ordem sequencial. Usamos a sequência de Jacobsthal para definir grupos de inserção.
*   **Sequência:** $1, 3, 5, 11, 21, 43, \dots$ (começamos o loop a partir do 3).
*   Isso define os índices dos perdedores que vamos processar.

**Lógica do Loop:**
1.  Pegamos o próximo número de Jacobsthal (ex: 3).
2.  Inserimos os perdedores **decrescendo** desse índice até o último inserido.
    *   Ordem de inserção: $b_3$, depois $b_2$.
    *   Próximo grupo (Jacobsthal 5): Inserimos $b_5$, depois $b_4$.
    *   Próximo grupo (Jacobsthal 11): Inserimos $b_{11}, b_{10}, \dots, b_6$.

#### 5.3. Busca Binária
Para inserir um elemento $b_i$:
1.  Sabemos que $b_i < a_i$.
2.  Logo, só precisamos procurar espaço na lista **antes** de onde o $a_i$ está posicionado atualmente.
3.  Usamos `std::lower_bound` para encontrar a posição correta com complexidade $O(\log n)$.
4.  Inserimos o elemento.

### Fase 6: Finalizar Ímpar
Se na Fase 1 removemos um `straggler`:
1.  Usamos `std::lower_bound` na cadeia inteira agora ordenada.
2.  Inserimos o `straggler` na posição correta.

---

## Exemplo Visual (Trace)

Vamos simular com: `[23, 76, 2, 45, 9, 3]` ($N=6$)

**1. Emparelhamento:**
*   Par A: (23, 76) -> Winner: **76**, Loser: 23
*   Par B: (2, 45) -> Winner: **45**, Loser: 2
*   Par C: (9, 3) -> Winner: **9**, Loser: 3

**2. Recursão (Ordenar Winners):**
*   Lista Winners: `[76, 45, 9]`
*   *...magia da recursão...*
*   Lista Winners Ordenada (`mainChain`): `[9, 45, 76]`

**3. Mapeamento ($a \rightarrow b$):**
*   $a_1 = 9$  (seu par era 3, então $b_1 = 3$)
*   $a_2 = 45$ (seu par era 2, então $b_2 = 2$)
*   $a_3 = 76$ (seu par era 23, então $b_3 = 23$)

**4. Inserção:**
*   **Passo Grátis:** Inserir $b_1$ (3) no início.
    *   Chain: `[3, 9, 45, 76]`
*   **Jacobsthal (próximo é 3):** Precisamos inserir até $b_3$.
    *   Ordem inversa: Inserir $b_3$, depois $b_2$.

    *   **Inserindo $b_3$ (23):**
        *   O "pai" é $a_3$ (76).
        *   Busca binária em `[3, 9, 45]`. Posição encontrada: entre 9 e 45.
        *   Chain: `[3, 9, 23, 45, 76]`

    *   **Inserindo $b_2$ (2):**
        *   O "pai" é $a_2$ (45).
        *   Busca binária em `[3, 9, 23]` (tudo antes do 45). Posição encontrada: início.
        *   Chain: `[2, 3, 9, 23, 45, 76]`

**Resultado Final:** `[2, 3, 9, 23, 45, 76]`

---

## Pontos Chave para Implementação em C++

1.  **`std::lower_bound`:** É essencial.
    *   Sintaxe: `lower_bound(inicio, fim, valor)`.
    *   Retorna um iterador para a primeira posição onde `elemento >= valor`. É aí que você insere.
2.  **Iteradores:** Ao inserir em um `std::vector`, os iteradores podem ser invalidados. Por isso, a lógica de Jacobsthal geralmente recalcula limites ou usa índices, ou confia que `lower_bound` busca do início até o ponto de corte seguro.
3.  **Templates:** Como o exercício pede `vector` e `deque`, crie a lógica uma vez usando `template <typename Container>` para evitar escrever o código duas vezes.

## Por que Jacobsthal?
A sequência de Jacobsthal garante que o número de elementos na `mainChain` (contra os quais faremos busca binária) seja sempre uma potência de 2 menos 1 ($2^k - 1$). Isso maximiza a eficiência da busca binária, garantindo que o "worst case" de comparações seja o mínimo teórico possível.