/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:28:48 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/22 08:35:02 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <string>

#define RESET "\033[0m"    // Reset color and style
#define RED "\033[1;31m"   // Bold red color
#define GREEN "\033[1;32m" // Bold green color

class PhoneBook
{
  private:
	static const int maxContacts = 8;
	Contact contacts[maxContacts];
	int contactsCount;

	void isPhoneBookFull();
    std::string getValidInput(const std::string& fieldName);
    std::string getValidInputNumber(const std::string& fieldName);
	std::string truncateString(const std::string &str);
    Contact createNewContact();
    void saveContact(const Contact& newContact);
	
  public:
	PhoneBook() : contactsCount(0) {}
	~PhoneBook(){};

	void setCabecalho(void);
	void printMessage(void);
	void addContact(void);
	void searchContact(void);
};

#endif
