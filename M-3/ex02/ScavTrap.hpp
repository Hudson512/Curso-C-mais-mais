/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:15:56 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/10 09:08:46 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_CPP
#define SCAVTRAP_CPP

#define RESET       "\033[0m"
#define GREEN       "\033[32m"
#define BLUE        "\033[34m"
#define RED         "\033[31m"
#define YELLOW      "\033[33m"

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ~ScavTrap();
    
    void attack(const std::string& target);
    void guardGate();
};

#endif