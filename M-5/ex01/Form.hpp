/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:29:06 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/02 10:39:55 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

# ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form
{
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
    
public:
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    // Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Member functions
    void beSigned(const Bureaucrat &bureaucrat);

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
};

std::ostream &operator<<(std::ostream &os, const Form &form);



#endif