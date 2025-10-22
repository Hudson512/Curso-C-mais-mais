/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:41:07 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/22 09:46:13 by hmateque         ###   ########.fr       */
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
#include <cerrno> 

struct ScalarConverterData
{
    float floatValue;
    double doubleValue;
    char *end;
};


class ScalarConverter
{
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
        
        static void print_impossible();
        static void printConversions(double doubleValue);
    public:
        static void convert(const char *literal);
};

#endif