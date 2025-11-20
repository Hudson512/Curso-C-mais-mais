/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 00:07:53 by hmateque          #+#    #+#             */
/*   Updated: 2025/11/20 16:20:39 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);

    std::deque<int> dq;
    dq.push_back(100);
    dq.push_back(200);

    // Testes positivos
    try {
        std::cout << "Found vector: " << easyfind(v, 20) << std::endl;
    } catch(const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "Found list: " <<  easyfind(lst, 1) << std::endl;
    } catch(const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    const std::vector<int> cv = v;
    try {
        std::cout << "Found const: " << easyfind(cv, 30) << std::endl;
    } catch(const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "Found deque: " << easyfind(dq, 200) << std::endl;
    } catch(const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    // Testes negativos
    
    try {
        std::cout << "Found vector: " << easyfind(v, 99) << std::endl;
    } catch(const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "Found list: " <<  easyfind(lst, 42) << std::endl;
    } catch(const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "Found deque: " << easyfind(dq, 300) << std::endl;
    } catch(const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Teste NULL: " << easyfind(dq, NULL) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
