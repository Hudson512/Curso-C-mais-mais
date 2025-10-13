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
#include <cctype>
#include <limits>

class ScalarConverter
{
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
        // --------------------------------------------------------// 
        static bool isChar(const std::string &s) {
            return s.length() == 3 && s.front() == '\'' && s.back() == '\'';
        }

        static bool isInt(const std::string &s) {
            size_t i = 0;
            if (s[i] == '+' || s[i] == '-') i++;
            for (; i < s.size(); i++) {
                if (!isdigit(s[i])) return false;
            }
            return true;
        }

        static bool isFloat(const std::string &s) {
            if (s == "nanf" || s == "+inff" || s == "-inff") return true;
            if (s.back() != 'f') return false;
            return s.find('.') != std::string::npos;
        }

        static bool isDouble(const std::string &s) {
            if (s == "nan" || s == "+inf" || s == "-inf") return true;
            return s.find('.') != std::string::npos && s.back() != 'f';
        }

        // ---------- CONVERSÃO ----------
        static void handleChar(const std::string &s) {
            char c = s[1];
            std::cout << "Detectado tipo: char → valor: '" << c << "' (" << (int)c << ")\n";
        }

        static void handleInt(const std::string &s) {
            try {
                int n = std::stoi(s);
                std::cout << "Detectado tipo: int → valor: " << n << "\n";
            } catch (...) {
                std::cout << "Erro ao converter para int\n";
            }
        }

        static void handleFloat(const std::string &s) {
            try {
                float f = std::stof(s);
                std::cout << "Detectado tipo: float → valor: " << f << "f\n";
            } catch (...) {
                std::cout << "Erro ao converter para float\n";
            }
        }

        static void handleDouble(const std::string &s) {
            try {
                double d = std::stod(s);
                std::cout << "Detectado tipo: double → valor: " << d << "\n";
            } catch (...) {
                std::cout << "Erro ao converter para double\n";
            }
        }
    public:
        static void convert(const std::string literal);
};

#endif