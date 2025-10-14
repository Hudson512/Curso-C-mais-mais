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

    if (ac != 2)
    {
        std::cerr << "Usage: ./scalar_converter <literal_value>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}