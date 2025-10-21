/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:01:19 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/21 10:02:25 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// =====================
// Função generate()
// =====================
Base* generate(void)
{
    srand(static_cast<unsigned int>(time(NULL)));
    int r = rand() % 3;

    switch (r)
    {
        case 0:
            std::cout << "🔹 Gerado tipo A" << std::endl;
            return new A();
        case 1:
            std::cout << "🔸 Gerado tipo B" << std::endl;
            return new B();
        default:
            std::cout << "🔺 Gerado tipo C" << std::endl;
            return new C();
    }
}

// =====================
// identify(Base* p)
// =====================
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Identificado: A (via ponteiro)" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identificado: B (via ponteiro)" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identificado: C (via ponteiro)" << std::endl;
    else
        std::cout << "Tipo desconhecido" << std::endl;
}

// =====================
// identify(Base& p)
// =====================
void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Identificado: A (via referência)" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Identificado: B (via referência)" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Identificado: C (via referência)" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    std::cout << "Tipo desconhecido" << std::endl;
}
