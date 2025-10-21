/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:01:19 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/21 21:58:07 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include "includes/A.hpp"
#include "includes/B.hpp"
#include "includes/C.hpp"

// Função generate()
Base* generate(void)
{
    srand(static_cast<unsigned int>(time(NULL)));
    int r = rand() % 3;

    switch (r)
    {
        case 0:
            std::cout << "Classe do tipo A, criada" << std::endl;
            return new A();
        case 1:
            std::cout << "Classe do tipo B, criada" << std::endl;
            return new B();
        default:
            std::cout << "Classe do tipo C, criada" << std::endl;
            return new C();
    }
}

// identify(Base* p)
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Identificado: Classe do tipo A*" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identificado: Classe do tipo B*" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identificado: Classe do tipo C*" << std::endl;
    else
        std::cout << "Tipo (*) desconhecido" << std::endl;
}

// identify(Base& p)
void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Identificado: Classe do tipo A&" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Identificado: Classe do tipo B&" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Identificado: Classe do tipo C&" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    std::cout << "Tipo (&) desconhecido" << std::endl;
}
