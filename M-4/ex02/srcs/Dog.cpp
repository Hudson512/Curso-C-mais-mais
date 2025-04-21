/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:50:57 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/15 19:06:06 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../headers/Dog.hpp"

Dog::Dog() {
    type = "Dog";
    brain = new Brain();
    std::cout << "[Dog] Constructor called\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "[Dog] copy constructor called\n";
}

Dog& Dog::operator=(const Dog& other){
    if (this != &other){
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "[Dog] Assignment operator called\n";
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "[Dog] Destructor called\n";
}

void Dog::makeSound() const {
    std::cout << "[Dog] Woof woof!\n";
}

void Dog::setIdea(int index, const std::string& idea) {
    if (brain)
        brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return brain ? brain->getIdea(index) : "";
}

