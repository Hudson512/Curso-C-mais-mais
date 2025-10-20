/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:12:17 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/20 11:43:00 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Serializer.hpp"


Serializer::Serializer(){/*construturo default*/ }

Serializer::Serializer(const Serializer &other)
{
    (void)other;
}

Serializer::~Serializer(){/*Destrutor*/}

Serializer &Serializer::operator=(const Serializer &other)
{
    (void)other;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
