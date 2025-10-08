/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:41:07 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/08 12:48:39 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SCALAR_CONVERTER_HPP
# define  SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
        ScalarConverter();
        ScalarConverter &ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
    public:
        static void convert(const std::string literal);
};

#endif