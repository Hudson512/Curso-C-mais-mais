/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookAddContact.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:24:18 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/22 13:13:19 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

void PhoneBook::isPhoneBookFull()
{
    if (contactsCount >= maxContacts)
    {
        for (int i = 0; i < maxContacts - 1; ++i)
             contacts[i] = contacts[i + 1];
        --contactsCount;
    }
}

std::string PhoneBook::getValidInput(const std::string& fieldName)
{
    std::string input;
    do {
        std::cout << "Enter " << fieldName << ": ";
        std::getline(std::cin, input);
        
        if (std::cin.eof())
        {
			std::cout << RED "Fraud attempt detected, you have been blocked from the system." RESET << std::endl;
        	exit(1);
		}
    } while (input.empty());
    return input;
}

std::string PhoneBook::getValidInputNumber(const std::string& fieldName)
{
    std::string input;
    do {
        std::cout << "Enter " << fieldName << ": ";
        std::getline(std::cin, input);
        
        if (input.find_first_not_of("0123456789") != std::string::npos)
        {
            std::cout << fieldName << RED " must be a number. Please try again." RESET << std::endl;
            input = "";
        }
        else if (std::cin.eof())
        {
			std::cout << RED "Fraud attempt detected, you have been blocked from the system." RESET << std::endl;
        	exit(1);
		}
    } while (input.empty());
    return input;
}

int ft_valid(Contact newContact)
{
    if (newContact.getFirstName().empty() || newContact.getLastName().empty() || newContact.getNickname().empty() || newContact.getPhoneNumber().empty() || newContact.getDarkestSecret().empty())
        return 0;
    return 1;
}

Contact PhoneBook::createNewContact()
{
    Contact newContact;
    
    newContact.setFirstName(getValidInput("first name"));
    newContact.setLastName(getValidInput("last name"));
    newContact.setNickname(getValidInput("nickname"));
    newContact.setPhoneNumber(getValidInputNumber("phone number"));
    newContact.setDarkestSecret(getValidInput("darkest secret"));
    
    return newContact;
}

void PhoneBook::saveContact(const Contact& newContact)
{
    contacts[contactsCount] = newContact;
    contactsCount++;
    std::cout << GREEN "Contact added successfully!" RESET << std::endl;
}

void PhoneBook::addContact(void)
{
    isPhoneBookFull();
    Contact newContact = createNewContact();
    if (ft_valid(newContact))
        saveContact(newContact);
    else
    {
        std::cout << RED "Fraud attempt detected, you have been blocked from the system." RESET << std::endl;
        exit(1);
    }
}
