/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:38:48 by hmateque          #+#    #+#             */
/*   Updated: 2025/11/20 18:51:37 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "=== Teste do Subject ===" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "top element: "<< mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\n=== Teste com std::list para comparar ===" << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);

    std::cout << "last element: " << lst.back() << std::endl;

    lst.pop_back();

    std::cout << "Size: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
        std::cout << *lit << std::endl;

    std::cout << "\n=== Teste reverse iterator (Visão correcta de uma stack - pilha) ===" << std::endl;

    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << std::endl;

    std::cout << "\n=== Teste cópia ===" << std::endl;
    MutantStack<int> copy(mstack);
    for (MutantStack<int>::iterator cit = copy.begin(); cit != copy.end(); ++cit)
        std::cout << *cit << " ";
    std::cout << std::endl;

    return 0;
}
