/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:29:18 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/30 11:29:10 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Array.hpp"

int main() 
{
    {
        std::cout << "===== TESTE 1: Array vazio =====" << std::endl;
        try 
        {
            Array<int> a;
            
            std::cout << "Size inicial do Array a: " << a.size() << std::endl;

            // Passando indece fora do limite do array
            a[0] = 999;
        }
        catch (std::exception &e) {
            std::cerr << "Erro: " << e.what() << std::endl << std::endl;
        }
    }
    
    {
        try {
            std::cout << "===== TESTE 2: Array<int> com 5 elementos =====" << std::endl;
            Array<int> a(5);

            std::cout << "Size inicial do Array a: " << a.size() << std::endl;
            
            for (unsigned int i = 0; i < a.size(); i++)
                a[i] = i * 10;

            std::cout << "Array a: ";
            for (unsigned int i = 0; i < a.size(); i++)
                std::cout << a[i] << " ";
            std::cout << std::endl;

            Array<int> b = a;
            b[0] = 1000;

            std::cout << "Array a: " << a[0] << std::endl;
            std::cout << "Array b: " << b[0] << std::endl;

            // Passando indece fora do limite do array
            std::cout << b[10] << std::endl; 
        }
        catch (std::exception &e) {
            std::cerr << "Erro: " << e.what() << std::endl << std::endl;
        }
    }

    {
        std::cout << "===== TESTE 3: Array<std::string> =====" << std::endl;
        try {
            Array<std::string> palavras(3);
            palavras[0] = "Olá";
            palavras[1] = "mundo";
            palavras[2] = "42!";

            for (unsigned int i = 0; i < palavras.size(); i++)
                std::cout << palavras[i] << " ";
            std::cout << std::endl;

            Array<std::string> copia = palavras;
            copia[1] = "cadete";

            std::cout << "Original: " << palavras[1] << std::endl;
            std::cout << "Cópia: " << copia[1] << std::endl << std::endl;
        } catch (std::exception &e) {
            std::cerr << "Erro: " << e.what() << std::endl << std::endl;
        }
    }    

    {
        std::cout << "===== TESTE 4: Array<int> const (apenas leitura) =====" << std::endl;
        try {
            const Array<int> c(3);
            std::cout << "Tamanho const c: " << c.size() << std::endl;
            std::cout << "c[0]: " << c[0] << std::endl;
            std::cout << "c[1]: " << c[1] << std::endl;
            std::cout << "c[2]: " << c[2] << std::endl;

            // NÃO deve compilar: tentativa de escrever em array const
            //c[0] = 5;
        } catch (std::exception &e) {
            std::cerr << "Erro: " << e.what() << std::endl;
        }
    }

    return 0;
}
