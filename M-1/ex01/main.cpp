/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:35:47 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/29 12:13:05 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main(void)
{
    std::string name;
    do
    {
        std::cout << "Enter a name for new zombie: ";
        std::getline(std::cin, name);
        if (std::cin.eof())
        {
			std::cout << RED "Fraud attempt detected, you have been blocked from the system." RESET << std::endl;
        	exit(1);
		}
    } while (name.empty());

    Zombie *zombie = zombieHorde(10, name);
    for (size_t i = 0; i < 10; i++)
        zombie[i].announce();
    delete [] zombie;
    return (0);
}