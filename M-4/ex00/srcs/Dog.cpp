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
    std::cout << "[Dog] Constructor called\n";
}

Dog::~Dog() {
    std::cout << "[Dog] Destructor called\n";
}

void Dog::makeSound() const {
    std::cout << "[Dog] Woof woof!\n";
}
