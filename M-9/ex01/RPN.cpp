/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:53:25 by hmateque          #+#    #+#             */
/*   Updated: 2025/12/06 12:34:52 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RPN.hpp"

// Constructors
RPN::RPN() {}
RPN::~RPN() {}

RPN::RPN(const RPN &other) 
{
    (void)other;
}
RPN &RPN::operator=(const RPN &other) 
{
    (void)other;
    return *this;
}

// Evaluate RPN expression
int RPN::evaluate(const std::string &expression)
{
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        // DEBUG
        std::cout << "Token: " << token << std::endl;
        // Numeros negativos sao considerados
        char *endptr;
        long val = std::strtol(token.c_str(), &endptr, 10);
        
        if (*endptr == '\0') // Verifica se todo o token foi convertido
        {
            if (val >= 10 || val <= std::numeric_limits<int>::min())
                throw std::runtime_error("Error: The number must be less than 10 (< 10).");
            stack.push(static_cast<int>(val));
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2)
                throw std::runtime_error("Error: Insufficient values in the expression.");

            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result;

            if (token == "+")
            {
                std::cout << "Adding " << a << " + " << b << std::endl;
                result = a + b;
            }
            else if (token == "-")
            {
                std::cout << "Subtracting " << a << " - " << b << std::endl;
                result = a - b;
            }
            else if (token == "*") 
            {
                std::cout << "Multiplying " << a << " * " << b << std::endl;
                result = a * b;
            }
            else // token == "/"
            {
                if (b == 0)
                    throw std::runtime_error("Error: Division by zero.");
                result = a / b;
            }

            stack.push(result);
        }
        else
        {
            throw std::runtime_error("Error: Invalid token '" + token + "'.");
        }
        std::stack<int> debugStack = stack;
        std::cout << "Stack contents (top to bottom): ";
        while (!debugStack.empty())
        {
            std::cout << debugStack.top() << " ";
            debugStack.pop();
        }
        std::cout << std::endl;
    }
    std::cout << "Final stack size: " << stack.size() << std::endl;
    if (stack.size() == 1)
        return stack.top();
    else
        throw std::runtime_error("Error: The user input has too many values.");
}



