/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:55:13 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/17 12:22:45 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Animal.hpp"
#include "headers/Dog.hpp"
#include "headers/Cat.hpp"

#include <iostream>


int main() {
    {
        std::cout << "----- TESTE BÁSICO -----" << std::endl;
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        delete j;
        delete i;
    }
    
    {
        std::cout << "\n----- TESTE COM ARRAY -----" << std::endl;
        const int size = 4;
        Animal* zoo[size];

        for (int i = 0; i < size; ++i) {
            if (i < size / 2)
                zoo[i] = new Dog();
            else
                zoo[i] = new Cat();
        }

        for (int i = 0; i < size; ++i)
            delete zoo[i];
    }
    
    {
        std::cout << "\n----- TESTE DE DEEP COPY -----" << std::endl;
        Dog original;
        original.setIdea(0, "Chase the cat");
        original.setIdea(1, "Eat food");

        Dog copy = original;

        std::cout << "Original idea 0: " << original.getIdea(0) << std::endl;
        std::cout << "Copy idea 0   : " << copy.getIdea(0) << std::endl;

        original.setIdea(0, "Play with ball");

        std::cout << "After change - Original idea 0: " << original.getIdea(0) << std::endl;
        std::cout << "After change - Copy idea 0   : " << copy.getIdea(0) << std::endl;
    }
    
    return 0;
}
