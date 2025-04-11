/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:55:13 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/10 09:18:25 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap player1;
    ClapTrap player2("Player2");
    int defaultRepaired = 3;
    int defaultAttackDamage = 5;
    
    player1.setAttackDamage(defaultAttackDamage);
    player1.attack(player2.getName());
    player2.takeDamage(player1.getAttackDamage());
    player2.beRepaired(defaultRepaired);
    player2.attack(player1.getName());

    return 0;
}