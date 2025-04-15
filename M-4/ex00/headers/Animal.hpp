/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:38:25 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/15 18:38:28 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    std::string getType() const;
    virtual void makeSound() const;
};

#endif
