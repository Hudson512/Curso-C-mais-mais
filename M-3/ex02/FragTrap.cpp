/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:50:09 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/10 10:05:24 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << CYAN << "[ FragTrap ] " << name << " default constructor called!" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << CYAN << "[ FragTrap ] " << this->name << " is ready to party!" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << RED << "[ FragTrap ] " << name << " is out of service!" << RESET << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << CYAN << "[ FragTrap ] " << name << " launches an epic attack on " 
                  << target << ", dealing " << attackDamage << " damage!" << RESET << std::endl;
        energyPoints--;
    }
    else
    {
        std::cout << RED << "[ FragTrap ] Not enough energy or health to attack!" << RESET << std::endl;
    }
}

void FragTrap::highFivesGuys()
{
    std::cout << BLUE << "[ FragTrap ] " << name << " requests a high five! ✋" << RESET << std::endl;
}