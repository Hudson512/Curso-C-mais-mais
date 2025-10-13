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

ScalarConverter::ScalarConverter(const ScalarConverter &other){/*construturo copia*/}

ScalarConverter::~ScalarConverter(){/*Destrutor*/}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){/*Subrecarga de atribuicao*/}

void ScalarConverter::convert(const std::string literal)
{
    //1. Detectar o Tipo
    if (isChar(literal))
        handleChar(literal);
    else if (isInt(literal))
        handleInt(literal);
    else if (isFloat(literal))
        handleFloat(literal);
    else if (isDouble(literal))
        handleDouble(literal);
    else
        std::cout << "Tipo desconhecido!\n";
        
    //2. Convertê-lo da string para seu tipo real
    //Ex: a string de entrada for "42.0f", você a converterá para o tipo nativo float.
    
    // --- Fase 1: Detectar tipo ---
  
}

