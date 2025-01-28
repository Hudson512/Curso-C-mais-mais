/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:35:47 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/28 09:57:29 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main()
{
    std::string name;
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

    Zombie *zombie = newZombie(name);
    zombie->announce();
    randomChump("Random");
    delete zombie;
    return (0);
}