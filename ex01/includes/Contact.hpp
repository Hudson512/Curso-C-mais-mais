/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:24:07 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/18 02:15:03 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <climits>
# include <cstdlib>

class Contact
{
private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;

public:
  std::string getFirstName() const;
  void setFirstName(const std::string &firstName);
  std::string getLastName() const;
  void setLastName(const std::string &lastName);
  std::string getNickname() const;
  void setNickname(const std::string &nickname);
  std::string getPhoneNumber() const;
  void setPhoneNumber(const std::string &phoneNumber);
  std::string getDarkestSecret() const;
  void setDarkestSecret(const std::string &darkestSecret);
};

#endif
