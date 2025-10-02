/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 09:00:15 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/02 11:52:00 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
/*
RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.
*/

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("Robotomy default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& t)
    : AForm("RobotomyRequestForm", 72, 45), target(t) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) 
{
    if (this != &other)
        this->target = other.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

int RobotomyRequestForm::randomZeroOrOne() const
{
    std::srand(std::time(0));
    return (std::rand() % 2 == 0);
}


void RobotomyRequestForm::execute(const Bureaucrat& executor) const 
{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "BRRRRRRRRRRZzzzzzzzzzz..." << std::endl;


    if (randomZeroOrOne()) {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << target << " ❌💥!" << std::endl;
    }
}
