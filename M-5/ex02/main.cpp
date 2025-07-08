/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:28:32 by hmateque          #+#    #+#             */
/*   Updated: 2025/07/08 10:44:23 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"

int main() {
    

    try {
        Bureaucrat john("John", 130);
        ShrubberyCreationForm shrub("home");
        
        john.signForm(shrub);
        john.executeForm(shrub);
    } catch (std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat alice("Alice", 40);
        RobotomyRequestForm form("Bender");

        alice.signForm(form);
        alice.executeForm(form);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    try {
        Bureaucrat bob("Bob", 1);
        PresidentialPardonForm pardon("Arthur Dent");

        bob.signForm(pardon);
        bob.executeForm(pardon);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
