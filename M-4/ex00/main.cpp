/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:55:13 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:39 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "headers/Animal.hpp"
#include "headers/Dog.hpp"
#include "headers/Cat.hpp"

int main() {
    std::cout << "\n--- Animal Tests ---\n";
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Type: " << dog->getType() << "\n";
    std::cout << "Type: " << cat->getType() << "\n";

    cat->makeSound(); // Cat sound
    dog->makeSound(); // Dog sound
    meta->makeSound(); // Animal sound

    delete meta;
    delete dog;
    delete cat;

    return 0;
}
