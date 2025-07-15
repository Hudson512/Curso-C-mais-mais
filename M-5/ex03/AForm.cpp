/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:42:20 by hmateque          #+#    #+#             */
/*   Updated: 2025/07/01 10:54:13 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/AForm.hpp"
#include "./includes/Bureaucrat.hpp"

AForm::AForm() : name("Default AForm"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) 
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm() {}

// Getters
std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

// Member functions
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

// Exception classes
const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
    os << "AForm Name: " << AForm.getName() << "\n"
       << "Is Signed: " << (AForm.getIsSigned() ? "Yes" : "No") << "\n"
       << "Grade to Sign: " << AForm.getGradeToSign() << "\n"
       << "Grade to Execute: " << AForm.getGradeToExecute();
    return os;
}