/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:41:10 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/10 09:58:47 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#define RESET       "\033[0m"
#define GREEN       "\033[32m"
#define BLUE        "\033[34m"
#define RED         "\033[31m"
#define YELLOW      "\033[33m"
#define CYAN        "\033[36m"

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
public:
    FragTrap();
    FragTrap(const std::string& name);
    ~FragTrap();
    
    void attack(const std::string& target);
    void highFivesGuys(void);
};



#endif