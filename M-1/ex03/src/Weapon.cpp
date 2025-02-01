/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 08:18:28 by hmateque          #+#    #+#             */
/*   Updated: 2025/02/01 08:19:08 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon() {}

std::string const &Weapon::getType()
{
    return (_type);
}

void Weapon::setType(std::string type)
{
    _type = type;
}