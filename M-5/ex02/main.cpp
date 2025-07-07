/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:28:32 by hmateque          #+#    #+#             */
/*   Updated: 2025/07/07 11:23:26 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    Bureaucrat john("John", 130); // suficiente para assinar e executar
    ShrubberyCreationForm shrub("home");

    try {
        john.signForm(shrub);     // deve assinar
        john.executeForm(shrub);  // deve criar o arquivo "home_shrubbery"
    } catch (std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
