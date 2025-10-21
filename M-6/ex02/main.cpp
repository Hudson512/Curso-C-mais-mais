/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:03:53 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/21 10:06:29 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Declara as funções
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void)
{
    Base* base = generate();

    std::cout << "\n--- Testando identify(Base*) ---" << std::endl;
    identify(base);

    std::cout << "\n--- Testando identify(Base&) ---" << std::endl;
    identify(*base);

    delete base;
    return 0;
}
