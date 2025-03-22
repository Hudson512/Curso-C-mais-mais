/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:35:43 by hmateque          #+#    #+#             */
/*   Updated: 2025/03/22 09:17:13 by hmateque         ###   ########.fr       */
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
    
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif