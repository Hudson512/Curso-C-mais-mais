/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:40:37 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/18 02:44:46 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;

    phoneBook.printMessage();
    while (true)
    {
        std::cout << "Phonebook> ";
    
        std::getline(std::cin, command);
    
        if (command == "ADD")
        {
            phoneBook.printMessage();
            phoneBook.addContact();
        }
        else if (command == "SEARCH" || command == "SCH")
        {
            phoneBook.printMessage();
            phoneBook.searchContact();
        }
        else if (command == "EXIT" || std::cin.eof())
        {
            std::cout << RED "Goodbye!" RESET << std::endl;
            break;
        }
        else
            std::cout << RED "Invalid command. Please try again." RESET << std::endl;
    }
    return (0);
}
