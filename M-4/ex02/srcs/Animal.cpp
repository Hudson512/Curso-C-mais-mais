/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:38:05 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/15 19:05:47 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../headers/Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "[Animal] Constructor called\n";
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "[Animal] Copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "[Animal] Copy assignment operator called\n";
    if (this != &other)
        type = other.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "[Animal] Destructor called\n";
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "[Animal] makes a generic sound\n";
}
