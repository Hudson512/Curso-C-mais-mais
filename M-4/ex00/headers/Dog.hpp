/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:49:47 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/15 18:49:50 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    virtual ~Dog();
    void makeSound() const;
};

#endif
