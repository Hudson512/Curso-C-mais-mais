/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 01:09:23 by hmateque          #+#    #+#             */
/*   Updated: 2025/11/20 17:21:20 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    std::cout << "=== Teste do subject ===" << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n=== Teste com range de iteradores ===" << std::endl;
    std::vector<int> v;
    v.push_back(100);
    v.push_back(200);
    v.push_back(300);
    try
    {
        Span sp2 = Span(5);
        sp2.addNumber(-10);
        sp2.addNumber(20);
        sp2.addRange(v.begin(), v.end());
        std::cout << "Short span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\n=== Teste com 10.000 números ===" << std::endl;
    try
    {
        Span sp3(10000);
        std::srand(std::time(NULL));

        for (int i = 0; i < 10000; i++)
            sp3.addNumber(std::rand());

        std::cout << "Shortest: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp3.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
