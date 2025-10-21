/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:03:53 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/21 22:01:12 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <unistd.h>
#include "includes/Base.hpp"
#include "includes/A.hpp"
#include "includes/B.hpp"
#include "includes/C.hpp"

// Declara as funções
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void)
{
    std::cout << "=========================================================================" << std::endl;
    sleep(2);
    Base* base = generate();

    std::cout << "\n--- Testando identify(Base*) ---" << std::endl;
    identify(base);

    std::cout << "\n--- Testando identify(Base&) ---" << std::endl;
    identify(*base);
    std::cout << "=========================================================================" << std::endl;


    delete base;
    return 0;
}
