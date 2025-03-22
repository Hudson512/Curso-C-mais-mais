/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:35:25 by hmateque          #+#    #+#             */
/*   Updated: 2025/03/22 09:19:40 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.hpp"

// Constructores
Fixed::Fixed() : _value(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits){
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits))){
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

// Operadores

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called " << std::endl;
    if (this != &fixed)
        this->_value = fixed.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

// Destructor
Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

// Metodos
float Fixed::toFloat(void) const
{
    return (float)this->_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->_value >> _fractionalBits;
}

int Fixed::getRawBits(void) const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}