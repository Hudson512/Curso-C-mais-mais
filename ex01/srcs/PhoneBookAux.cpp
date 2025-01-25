/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookAux.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:24:05 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/25 12:37:59 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

std::string PhoneBook::truncateString(const std::string &str)
{
  static const int width = 10;
  
  if (str.length() > width)
    return str.substr(0, width - 1) + '.';
  return str;
}

void PhoneBook::printMessage(void)
{
    std::cout << "#################### Phonebook ####################\n";
    std::cout << "##                                               ##\n";
    std::cout << "##     ADD - Add a new contact.                  ##\n";
    std::cout << "##     SEARCH - Display contact info.            ##\n";
    std::cout << "##     EXIT - Exit phonebook.                    ##\n";
    std::cout << "##                                               ##\n";
    std::cout << "###################################################\n";
}

void	PhoneBook::setCabecalho(void)
{
	std::cout << std::setw(10) << "Index"
				<< "|" << std::setw(10) << "First Name"
				<< "|" << std::setw(10) << "Last Name"
				<< "|" << std::setw(10) << "Nickname" << std::endl;
	std::cout << std::string(44, '-') << std::endl;
}

void PhoneBook::searchContact(void)
{
	if (contactsCount == 0)
	{
    	std::cout << RED "Phonebook is empty.\n" RESET;
    	return;
  	}
	PhoneBook::setCabecalho();
	for (int i = 0; i < contactsCount; i++)
	{
		std::cout << std::setw(10) << i << "|"
					<< std::setw(10) << truncateString(contacts[i].firstName) << "|"
					<< std::setw(10) << truncateString(contacts[i].lastName) << "|"
					<< std::setw(10) << truncateString(contacts[i].nickname) << std::endl;
	}
	
	while (1)
	{
		int index;
		
		std::cout << "Digite o index do contato: ";
		std::cin >> index;
		
		if (std::cin.eof())
		{
			std::cout << RED "Fraud attempt detected, you have been blocked from the system." RESET << std::endl;
        	exit(1);
		}
		if (std::cin.fail() || index >= contactsCount || index < 0)
   		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "Indice invalido. Insira um indice entre 0-"
						<< contactsCount - 1 << "." << std::endl;
			break;
    	}
		else if (index >= 0 && index < contactsCount)
		{
			std::cout << "First Name: " << contacts[index].firstName << std::endl;
			std::cout << "Last Name: " << contacts[index].lastName << std::endl;
			std::cout << "Nickname: " << contacts[index].nickname << std::endl;
			std::cout << "Number: " << contacts[index].phoneNumber << std::endl;
			std::cout << "Darkest Secret: " << contacts[index].darkestSecret << std::endl;
		}
	}
}
