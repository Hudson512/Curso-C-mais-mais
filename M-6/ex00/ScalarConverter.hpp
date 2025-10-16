/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:41:07 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/13 11:39:27 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SCALAR_CONVERTER_HPP
# define  SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>

/*
INT_MAX: 2147483647
INT_MIN: -2147483648
*/
struct ScalarConverterData
{
    int intValue;
    float floatValue;
    double doubleValue;
    std::string charValue;
    char *end;
};


class ScalarConverter
{
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
        
        static void print_impossible(int intCase);
        static void printConversions(double doubleValue);
    public:
        static void convert(const char *literal);
};

#endif