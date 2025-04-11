/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:00:43 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/10 09:11:41 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Player default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "[ ClapTrap ] default constructor called" << std::endl;
}


ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "[ ClapTrap ] constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    if (this != &other)
        *this = other;
    std::cout << "[ ClapTrap ] copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "[ ClapTrap ] " << name << " destructor called" << std::endl;
}

// Função de ataque
void ClapTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << "[ ClapTrap ] " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
    else
    {
        std::cout << "[ ClapTrap ] Not enough energy or hit points to attack!" << std::endl;
    }
}

// Função de quem sofre o ataque
void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << "[ ClapTrap ] " << name << " is already dead!" << std::endl;
    }
    else
    {
        hitPoints -= amount;
        if (hitPoints <= 0)
        {
            std::cout << "[ ClapTrap ] " << name << " has been defeated!" << std::endl;
            hitPoints = 0;
        }
        else
        {
            std::cout << "[ ClapTrap ] " << name << " has taken " << amount << " points of damage!" << std::endl;
        }
    }
}

// Função para se recuperar
void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints <= 0)
    {
        std::cout << "[ ClapTrap ] " << name << " cannot be repaired!" << std::endl;
    }
    else
    {
        hitPoints += amount;
        energyPoints--;
        std::cout << "[ ClapTrap ] " << name << " has been repaired for " << amount << " hit points!" << std::endl;
    }
}

std::string ClapTrap::getName(void) const
{
    return this->name;
}

int ClapTrap::getAttackDamage(void)
{
    return this->attackDamage;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
    if (attackDamage > 0)
        this->attackDamage = attackDamage;
}