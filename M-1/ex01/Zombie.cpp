/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:15:46 by hmateque          #+#    #+#             */
/*   Updated: 2025/02/06 08:50:34 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static int  is_space(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\v' && str[i] != '\f' && str[i] != '\r')
            return (0);
        i++;
    }
    return (1);
}
Zombie::Zombie()
{
    return;
}

Zombie::Zombie(std::string name)
{
    if (is_space((char *)name.c_str()))
        this->name = "Zombie";
    else
        this->name = name;
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
