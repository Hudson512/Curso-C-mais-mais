/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:55:13 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/10 09:57:58 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    {
        std::cout << "=== ClapTrap Test ===" << std::endl;
        ClapTrap player1;
        ClapTrap player2("Player2");
        int defaultRepaired = 3;
        int defaultAttackDamage = 5;

        player1.setAttackDamage(defaultAttackDamage);
        player1.attack(player2.getName());
        player2.takeDamage(player1.getAttackDamage());
        player2.beRepaired(defaultRepaired);
        player2.attack(player1.getName());
    }
    
    {
        std::cout << "\n=== ScavTrap Test ===" << std::endl;
        ScavTrap scav1;
        ScavTrap scav2("ScavyTwo");
        int scavRepaired = 10;
        int scavAttack = 15;

        scav1.setAttackDamage(scavAttack);
        scav1.attack(scav2.getName());
        scav2.takeDamage(scav1.getAttackDamage());
        scav2.beRepaired(scavRepaired);
        scav2.attack(scav1.getName());

        scav2.guardGate();
    }

    {
        std::cout << "\n=== FragTrap Test ===" << std::endl;
        FragTrap frag1;
        FragTrap frag2("Fraggy");

        int fragRepaired = 20;
        int fragAttack = 25;

        frag1.setAttackDamage(fragAttack);
        frag1.attack(frag2.getName());
        frag2.takeDamage(frag1.getAttackDamage());
        frag2.beRepaired(fragRepaired);
        frag2.attack(frag1.getName());

        frag2.highFivesGuys();
    }

    return 0;
}

