/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:09:51 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/29 12:02:52 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

# define RED "\033[31m"
# define RESET "\033[0m"

class Zombie
{
    private:
        std::string name;

    public:
        Zombie();
        ~Zombie();
        void announce(void);
        void setName(std::string name);

};

Zombie* zombieHorde( int N, std::string name );

#endif
    