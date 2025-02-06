/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:01:52 by hmateque          #+#    #+#             */
/*   Updated: 2025/02/06 09:09:11 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static std::string intToString(int num) {
    std::ostringstream oss;
    oss << num;
    return oss.str();
}

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        horde[i] = Zombie(name + intToString(i + 1));
    }
    return horde;
}