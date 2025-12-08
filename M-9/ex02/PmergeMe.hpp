/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:21:50 by hmateque          #+#    #+#             */
/*   Updated: 2025/12/08 16:25:18 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>
#include <sys/time.h> // POSIX: gettimeofday para alta precisão
#include <stdexcept>
#include <cstdlib>
#include <iomanip>

class PmergeMe {
    public:
        static void process(int argc, char* argv[]);

    private:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        // Funções auxiliares para timing e display
        static double getTimeInUs(struct timeval start, struct timeval end);
        static void displayContainer(const std::string& prefix, const std::vector<int>& container);
        static void displayContainer(const std::string& prefix, const std::deque<int>& container);
        
        // Funções para o algoritmo de ordenação Merge-Insert (Ford-Johnson)
        // Você precisará implementar a lógica aqui. 
        // A complexidade do algoritmo Ford-Johnson requer sub-funções.
        template <typename Container>
        static void mergeInsertSort(Container& container);

        // Funções específicas para cada container (conforme sugerido no enunciado para evitar genéricos complexos)
        static void sortVector(std::vector<int>& vec);
        static void sortDeque(std::deque<int>& deq);
};

#endif // PMERGEME_HPP
