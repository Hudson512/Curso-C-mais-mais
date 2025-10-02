/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:28:32 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/02 10:39:49 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

int main() 
{
    std::cout << "------------- \033[31mExample 1\033[0m -------------" << std::endl;
    try {
        Bureaucrat b("Hudson", 10);
        Form f("Formulário XPTO", 10, 5);

        std::cout << "*************************************" << std::endl;
        std::cout << "*            INFO FORM              *" << std::endl;
        std::cout << "*************************************" << std::endl;
        std::cout << f << std::endl;
        std::cout << "*************************************" << std::endl;
        std::cout << "*             INFO BURE             *" << std::endl;
        std::cout << "*************************************" << std::endl; 
        std::cout << b << std::endl;
        std::cout << "*************************************" << std::endl;
        b.signForm(f);
        std::cout << "*************************************" << std::endl;
        std::cout << "*          NEW INFO FORM            *" << std::endl;
        std::cout << "*************************************" << std::endl;
        std::cout << f << std::endl;
        std::cout << "*************************************" << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "\033[31mException: " << e.what() << "\033[0m" << std::endl;
    }
    
    std::cout << "------------- \033[31mExample 2\033[0m -------------" << std::endl;
    std::cout << "\nTeste com burocrata de nível baixo:\n";
    try {
        Bureaucrat low("João", 140);
        Form important("Classificado", 100, 50);

        std::cout << "*************************************" << std::endl;
        std::cout << "*            INFO FORM              *" << std::endl;
        std::cout << "*************************************" << std::endl;
        std::cout << important << std::endl;
        std::cout << "*************************************" << std::endl;
        std::cout << "*             INFO BURE             *" << std::endl;
        std::cout << "*************************************" << std::endl; 
        std::cout << low << std::endl;
        std::cout << "*************************************" << std::endl;
        low.signForm(important);
        std::cout << "*************************************" << std::endl;
        std::cout << "*          NEW INFO FORM            *" << std::endl;
        std::cout << "*************************************" << std::endl;
        std::cout << important << std::endl;
        std::cout << "*************************************" << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "\033[31mException: " << e.what() << "\033[0m" << std::endl;
    }

    return 0;
}
