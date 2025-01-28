/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:37:52 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/13 11:48:08 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

std::string messageUpperCase(std::string message) {
    for (size_t i = 0; i < message.length(); ++i) {
        if (std::isalpha(message[i]))
            message[i] = std::toupper(message[i]);
    }
    return (message);
}

int main(int argc, char **argv)
{
    if (argc == 1) 
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; i++)
    {
        std::cout << messageUpperCase(argv[i]);
    }
    std::cout << std::endl;
    return (0);
}
