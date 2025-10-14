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

void ScalarConverter::print_data(ScalarConverterData data)
{
    std::cout << "char: " << data.charValue << std::endl;
    std::cout << "int: " << data.intValue << std::endl;
    std::cout << "float: " << data.floatValue << std::endl;
    std::cout << "double: " << data.doubleValue << std::endl;
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

void ScalarConverter::convert(const char *literal)
{
    ScalarConverterData data;
    std::string str(literal);

    // 1. Verifica se é valor especial (nan, inf, etc)
    if (str == "nan" || str == "nanf" ||
        str == "+inf" || str == "+inff" ||
        str == "-inf" || str == "-inff")
    {
        // Trate como valor especial
        data.special = 1;
        data.doubleValue = std::strtod(literal, &data.end);
        data.floatValue = static_cast<float>(data.doubleValue);
        std::cout << "char: impossivel" << std::endl;
        std::cout << "int: impossivel" << std::endl;
        std::cout << "float: " << data.floatValue << "f" << std::endl;
        std::cout << "double: " << data.doubleValue << std::endl;
        return;
    }

    // 2. Tenta converter para int
    std::istringstream iss_int(str);
    int intValue;
    iss_int >> intValue;
    if (!iss_int.fail() && iss_int.eof())
    {
        // É um int válido
        if (intValue >= 32 && intValue <= 126)
            std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
        else
            std::cout << "char: Não exibível" << std::endl;
        std::cout << "int: " << intValue << std::endl;
        std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
        return;
    }

    // 3. Tenta converter para float (termina com 'f')
    if (str.length() > 1 && str[str.length() - 1] == 'f')
    {
        std::string floatPart = str.substr(0, str.length() - 1);
        std::istringstream iss_float(floatPart);
        float floatValue;
        iss_float >> floatValue;
        if (!iss_float.fail() && iss_float.eof())
        {
            if (floatValue >= 32 && floatValue <= 126)
                std::cout << "char: '" << static_cast<char>(floatValue) << "'" << std::endl;
            else
                std::cout << "char: Não exibível" << std::endl;
            std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
            std::cout << "float: " << floatValue << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(floatValue) << std::endl;
            return;
        }
    }

    // 4. Tenta converter para double
    std::istringstream iss_double(str);
    double doubleValue;
    iss_double >> doubleValue;
    if (!iss_double.fail() && iss_double.eof())
    {
        if (doubleValue >= 32 && doubleValue <= 126)
            std::cout << "char: '" << static_cast<char>(doubleValue) << "'" << std::endl;
        else
            std::cout << "char: Não exibível" << std::endl;
        std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
        std::cout << "float: " << static_cast<float>(doubleValue) << "f" << std::endl;
        std::cout << "double: " << doubleValue << std::endl;
        return;
    }

    // 5. Tenta converter para char (um único caractere não numérico)
    if (str.length() == 1 && !std::isdigit(str[0]))
    {
        char c = str[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    // Se não passou em nenhum teste, é inválido
    print_impossible(0);
}

int ScalarConverter::convert_int(const std::string &literal)
{
    // Implementação da conversão para int
    int intValue;
    std::istringstream iss(literal);
    iss >> intValue;
    if (iss.fail() || !iss.eof()) {
        throw 1;
    }
    
    return intValue;
}

float ScalarConverter::convert_float(const std::string &literal)
{
    // Implementação da conversão para float
    return 0.0f; // Placeholder
}

double ScalarConverter::convert_double(const std::string &literal)
{
    // Implementação da conversão para double
    return 0.0; // Placeholder
}

char ScalarConverter::convert_char(const std::string &literal)
{
    // Implementação da conversão para char
    return '\0'; // Placeholder
}

int ScalarConverter::check_error(const std::string &literal)
{
    // Implementação da verificação de erros
    return 0; // Placeholder
}