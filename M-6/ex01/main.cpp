/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:24:54 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/20 12:35:26 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Serializer.hpp"

int main(void)
{
    Data* data = new Data();
    data->id = 42;
    data->name = "Hmateque";
    data->value = 3.14f;

    std::cout << "Dados originais:" << std::endl;
    std::cout << "  id: " << data->id << std::endl;
    std::cout << "  name: " << data->name << std::endl;
    std::cout << "  value: " << data->value << std::endl;

    // Serializa o ponteiro
    uintptr_t raw = Serializer::serialize(data);
    std::cout << "\nPonteiro: " << &data << " serializado para (uintptr_t): " << raw << std::endl;
    
    // Desserializa o valor de volta para ponteiro
    std::cout << "\nInicio da desserialização..." << std::endl;
    
    Data* ptr = Serializer::deserialize(raw);
    
    std::cout << "\nApós desserialização:" << std::endl;
    std::cout << "  id: " << ptr->id << std::endl;
    std::cout << "  name: " << ptr->name << std::endl;
    std::cout << "  value: " << ptr->value << std::endl;

    // Verifica se o endereço é o mesmo
    std::cout << "\nComparação de ponteiros:" << std::endl;
    std::cout << "  &data = " << &data << std::endl;
    std::cout << "  ptr   = " << ptr << std::endl;        
    
    if (ptr == data)
        std::cout << "Sucesso! É o mesmo endereço." << std::endl;
    else
        std::cout << "Erro: endereços diferentes!" << std::endl;
    delete data;
    return 0;
}
