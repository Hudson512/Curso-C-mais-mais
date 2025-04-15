/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:57:45 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/15 18:57:48 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat();
    virtual ~Cat();
    void makeSound() const;
};

#endif
