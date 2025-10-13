/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:42:56 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/13 11:44:13 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"


int main(int ac, char *av[])
{
    ScalarConverter::convert("'a'");
    ScalarConverter::convert("42");
    ScalarConverter::convert("3.14f");
    ScalarConverter::convert("3.14");
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("-inf");
    return 0;
}