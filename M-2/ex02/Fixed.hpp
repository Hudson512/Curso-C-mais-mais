/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:35:43 by hmateque          #+#    #+#             */
/*   Updated: 2025/03/24 20:32:22 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
    int _value;
    static const int _fractionalBits = 8;
public:
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& fixed);
    Fixed();
    float toFloat(void) const;
    int toInt(void) const;
    
    Fixed& operator=(const Fixed& fixed);
    // Operadores aritméticos
    Fixed operator+(const Fixed& fixed) const;
    Fixed operator-(const Fixed& fixed) const;
    Fixed operator*(const Fixed& fixed) const;
    Fixed operator/(const Fixed& fixed) const;
    // Operadores de incremento/decremento
    Fixed& operator++(void);
    Fixed operator++(int);
    Fixed& operator--(void);
    Fixed operator--(int);
    // operadores de comparação
    bool operator>(const Fixed& fixed) const;
    bool operator<(const Fixed& fixed) const;
    bool operator>=(const Fixed& fixed) const;
    bool operator<=(const Fixed& fixed) const;
    bool operator==(const Fixed& fixed) const;
    bool operator!=(const Fixed& fixed) const;
    
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static Fixed const &min(Fixed const &a, Fixed const &b);
    static Fixed const &max(Fixed const &a, Fixed const &b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif