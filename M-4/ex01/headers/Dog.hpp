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
private:
    Brain* brain;
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();

    void makeSound() const;
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif
