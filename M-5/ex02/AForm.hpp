/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:29:06 by hmateque          #+#    #+#             */
/*   Updated: 2025/07/07 11:04:32 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
    
public:
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    // Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Member functions
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;

    // Exception classes
    class GradeTooHighException : public std::exception
    {
        public:
            const char * what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char * what() const throw();
    };
    
    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);



#endif