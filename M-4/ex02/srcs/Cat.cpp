/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:58:21 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/15 19:06:12 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../headers/Cat.hpp"

Cat::Cat() {
    type = "Cat";
    brain = new Brain();
    std::cout << "[Cat] Constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "[Cat ] Copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other){
    if (this != &other){
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "[Cat] Assignment operator called\n";
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "[Cat] Destructor called\n";
}

void Cat::makeSound() const {
    std::cout << "[Cat] Meow meow!\n";
}

void Cat::setIdea(int index, const std::string& idea) {
    if (brain)
        brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return brain ? brain->getIdea(index) : "";
}
