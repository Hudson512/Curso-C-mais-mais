/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:12:17 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/13 11:36:58 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(){/*construturo default*/ }

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    /*construturo copia*/
    (void)other;
}

ScalarConverter::~ScalarConverter(){/*Destrutor*/}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    /*Subrecarga de atribuicao*/
    (void)other;
    return *this;
}



void ScalarConverter::print_impossible(int intCase)
{
    switch (intCase)
    {
    case 1:
        std::cout << "char: " << "impossivel" << std::endl;
        break;
    case 2:
        std::cout << "int: " << "impossivel" << std::endl;
        break;
    case 3:
        std::cout << "float: " << "impossivel" << std::endl;
        break;
    case 4:
        std::cout << "double: " << "impossivel" << std::endl;
        break;
    
    default:
        std::cout << "char: " << "impossivel" << std::endl;
        std::cout << "int: " << "impossivel" << std::endl;
        std::cout << "float: " << "impossivel" << std::endl;
        std::cout << "double: " << "impossivel" << std::endl;
        break;
    }
    
}

void ScalarConverter::printConversions(double doubleValue)
{
    // char
    if (std::isprint(static_cast<char>(doubleValue)))
        std::cout << "char: '" << static_cast<char>(doubleValue) << "'" << std::endl;
    else if (doubleValue < std::numeric_limits<char>::min() || doubleValue > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: Não exibível" << std::endl;

    // int
    if (doubleValue >= static_cast<double>(std::numeric_limits<int>::min()) &&
        doubleValue <= static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
    else
        std::cout << "int: impossivel" << std::endl;

    // float
    std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(doubleValue);
    std::cout << "f" << std::endl;

    // double
    std::cout << std::fixed << std::setprecision(1) << "double: " << doubleValue;
    std::cout << std::endl;
}

void ScalarConverter::convert(const char *literal)
{
    ScalarConverterData data;
    std::string str(literal);

    // 1. Verifica se é valor especial (nan, inf, etc)
    if (str == "nan" || str == "nanf" ||
        str == "+inf" || str == "+inff" ||
        str == "-inf" || str == "-inff")
    {
        data.doubleValue = std::strtod(literal, &data.end);
        data.floatValue = static_cast<float>(data.doubleValue);
        std::cout << "char: impossivel" << std::endl;
        std::cout << "int: impossivel" << std::endl;
        std::cout << "float: " << data.floatValue << "f" << std::endl;
        std::cout << "double: " << data.doubleValue << std::endl;
        return;
    }

    // 2. Tenta converter para double
    double doubleValue = std::strtod(literal, &data.end);
    if ((data.end != literal && *data.end == '\0') ||
        (data.end != literal && *data.end == 'f' && *(data.end + 1) == '\0'))
    {
        if (str.length() > 1 && str[0] == ' ') {
            print_impossible(0);
            return;
        }
        printConversions(doubleValue);
        return;
    }


    // 3. Tenta converter para char (um único caractere não numérico)
    if (str.length() == 1 && !std::isdigit(str[0]))
    {
        char c = str[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0" << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    // Se não passou em nenhum teste, é inválido
    print_impossible(0);
}

