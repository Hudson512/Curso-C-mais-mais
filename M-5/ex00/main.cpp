/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:28:32 by hmateque          #+#    #+#             */
/*   Updated: 2025/09/26 11:12:14 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

int main() {
    std::cout << "------------- Example 1 -------------" << std::endl;
    try {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;

        a.incrementGrade();
        std::cout << a << std::endl;

        a.incrementGrade();
    }
    catch (std::exception& err) {
        std::cerr << "\033[31mException: " << err.what() << "\033[0m" << std::endl;
    }
    
    std::cout << "------------- Example 2 -------------" << std::endl;
    try {
        Bureaucrat b("Bob", 149);
        std::cout << b << std::endl;

        b.decrementGrade();
        std::cout << b << std::endl;

        b.decrementGrade();
    }
    catch (std::exception& err) {
        std::cerr << "\033[31mException: " << err.what() << "\033[0m" << std::endl;
    }
    
    std::cout << "------------- Example 3 -------------" << std::endl;
    try {
        Bureaucrat c("Charlie", 0);
    }
    catch (std::exception& err) {
        std::cerr << "\033[31mException: " << err.what() << "\033[0m" << std::endl;
    }

    return 0;
}
