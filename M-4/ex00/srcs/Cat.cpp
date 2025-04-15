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
    std::cout << "[Cat] Constructor called\n";
}

Cat::~Cat() {
    std::cout << "[Cat] Destructor called\n";
}

void Cat::makeSound() const {
    std::cout << "[Cat] Meow meow!\n";
}
