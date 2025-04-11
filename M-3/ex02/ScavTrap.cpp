/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:22:07 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/10 09:16:10 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << GREEN << "[ ScavTrap ] " << name << " default constructor called!" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << GREEN << "[ ScavTrap ] " << this->name << " has been assembled!" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << RED << "[ ScavTrap ] " << name << " has been dismantled!" << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << GREEN << "[ ScavTrap ] " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << RESET << std::endl;
        energyPoints--;
    }
    else
    {
        std::cout << RED << "[ ScavTrap ] Not enough energy or hit points to attack!" << RESET << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << YELLOW << "[ ScavTrap ] " << name << " is now in Gate Keeper mode!" << RESET << std::endl;
}