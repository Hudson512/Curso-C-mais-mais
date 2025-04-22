/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 07:53:15 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/22 07:53:34 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "[WrongCat] Constructor called\n";
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat] Destructor called\n";
}

void WrongCat::makeSound() const {
    std::cout << "[WrongCat] Meow??\n";
}
