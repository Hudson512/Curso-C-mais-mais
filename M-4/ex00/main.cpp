/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:55:13 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/22 08:03:43 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Animal.hpp"
#include "headers/WrongAnimal.hpp"
#include "headers/WrongCat.hpp"
#include "headers/Dog.hpp"
#include "headers/Cat.hpp"

int main() {
    {
        std::cout << "\n--- Animal Tests ---\n";
        const Animal* meta = new Animal();
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();

        std::cout << "Type: " << dog->getType() << "\n";
        std::cout << "Type: " << cat->getType() << "\n";

        cat->makeSound();
        dog->makeSound();
        meta->makeSound();

        delete meta;
        delete dog;
        delete cat;
    }

    {
        std::cout << "\n--- WrongAnimal Tests ---\n";
        const WrongAnimal* wrong = new WrongAnimal();
        const WrongAnimal* wrongCat = new WrongCat();

        std::cout << "Type: " << wrongCat->getType() << "\n";

        wrong->makeSound();
        wrongCat->makeSound();

        delete wrong;
        delete wrongCat;
    }

    return 0;
}
