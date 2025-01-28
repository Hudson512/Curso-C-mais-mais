/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:15:46 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/28 09:38:54 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    return;
}

Zombie::~Zombie()
{
    std::cout << this->name << ": " << "I'm dead" << std::endl;
    return;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}
