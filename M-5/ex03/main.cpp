/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:28:32 by hmateque          #+#    #+#             */
/*   Updated: 2025/07/15 14:38:50 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Intern.hpp"
#include "./includes/Bureaucrat.hpp"

int main() {
    Intern someIntern;
    Bureaucrat boss("Boss", 1);

    AForm* form1 = someIntern.makeForm("robotomy request", "Bender");
    AForm* form2 = someIntern.makeForm("shrubbery creation", "Garden");
    AForm* form3 = someIntern.makeForm("presidential pardon", "Marvin");
    AForm* invalid = someIntern.makeForm("make coffee", "Intern");

    if (form1) {
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }

    if (form2) {
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    }

    if (form3) {
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }

    if (invalid) delete invalid;

    return 0;
}

