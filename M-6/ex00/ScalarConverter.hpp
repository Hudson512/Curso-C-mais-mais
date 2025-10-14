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
    int error;
    char *end;
    int special;
};


class ScalarConverter
{
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
        static int convert_int(const std::string &literal);
        static float convert_float(const std::string &literal);
        static double convert_double(const std::string &literal);
        static char convert_char(const std::string &literal);
        static int check_error(const std::string &literal);
        static void print_data(ScalarConverterData data);
        static void print_impossible(int intCase);
    public:
        static void convert(const char *literal);
};

#endif