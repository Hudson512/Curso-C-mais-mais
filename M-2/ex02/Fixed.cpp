/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:35:25 by hmateque          #+#    #+#             */
/*   Updated: 2025/03/24 20:39:26 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.hpp"

// Constructores
Fixed::Fixed() : _value(0){}

Fixed::Fixed(const int value) : _value(value << _fractionalBits){}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits))){}

Fixed::Fixed(const Fixed& fixed)
{
    *this = fixed;
}

// Operadores

Fixed& Fixed::operator=(const Fixed& fixed)
{
    if (this != &fixed)
        this->_value = fixed.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

// Sobrecarrga de operadores de comparação
bool  Fixed::operator>(const Fixed& fixed) const
{
    return this->_value > fixed.getRawBits();
}

bool  Fixed::operator<(const Fixed& fixed) const
{
    return this->_value < fixed.getRawBits();
}

bool  Fixed::operator>=(const Fixed& fixed) const
{
    return this->_value >= fixed.getRawBits();
}

bool  Fixed::operator<=(const Fixed& fixed) const
{
    return this->_value <= fixed.getRawBits();
}

bool  Fixed::operator==(const Fixed& fixed) const
{
    return this->_value == fixed.getRawBits();
}

bool  Fixed::operator!=(const Fixed& fixed) const
{
    return this->_value != fixed.getRawBits();
}

// Sobrecarga de operadores aritméticos

Fixed Fixed::operator+(const Fixed& fixed) const
{
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
    return Fixed(this->toFloat() / fixed.toFloat());
}

// Sobrecarga de operadores de incremento/decremento

Fixed& Fixed::operator++()
{
    this->_value++;
    return *this;
}

Fixed& Fixed::operator--()
{
    this->_value--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->_value++;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->_value--;
    return tmp;
}

// Destructor
Fixed::~Fixed(){
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

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    return (a > b) ? a : b;
}