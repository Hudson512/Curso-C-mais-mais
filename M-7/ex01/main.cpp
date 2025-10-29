/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:35:27 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/29 11:05:26 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <string>
#include "iter.hpp"


void printConstString(const std::string &s)
{
    std::cout << s << std::endl;
}

void modifyStr(std::string &s) 
{
    s += "_Hackeado";
}

void printInt(const int &i) 
{
    std::cout << i << std::endl;
}


void increment(int &i) 
{
    i += 1;
}

int main() 
{
    int arr[] = { 0, 1, 2, 3, 4};
    const size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array int original:" << std::endl;
    ::iter(arr, arr_len, printInt);

    ::iter(arr, arr_len, increment);
    std::cout << "Depois de chamar a funcao, void increment(int &i):" << std::endl;
    ::iter(arr, arr_len, printInt);

    std::cout << std::endl;
   
    const std::string sarr1[] = { "chaine1", "chaine2", "chaine3" };
    std::string sarr2[] = { "chaine1", "chaine2", "chaine3" };
    
    const size_t sarr_len = sizeof(sarr1) / sizeof(sarr1[0]);

    std::cout << "Teste com array (sarr1) string const:" << std::endl;
    ::iter(sarr1, sarr_len, printConstString);

    std::cout << "Teste com array (sarr2) string no const:" << std::endl;
    ::iter(sarr2, sarr_len, modifyStr);
    std::cout << "Depois de chamar a funcao, void modifyStr(std::string &s):" << std::endl;
    ::iter(sarr2, sarr_len, printConstString);

    return 0;
}
