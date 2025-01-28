/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:38:18 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/28 09:50:11 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    if (name.empty())
        return (NULL);
    Zombie *zombie = new Zombie();
    zombie->setName(name);
    return (zombie);
}