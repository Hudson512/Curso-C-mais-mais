/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:13:07 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/17 10:41:19 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Brain.hpp"

Brain::Brain(){
    std::cout << "[Brain] Constructor called\n";
}

Brain::Brain(const Brain& other){
    std::cout << "[Brain] copy constructor called\n";
    for (int i = 0; i < 100; ++i)
        ideias[i] = other.ideias[i];
}

Brain& Brain::operator=(const Brain &other){
    std::cout << "[Brain] assignment operator called\n";
    if (this != &other){
        for (int i = 0; i < 100; ++i)
            ideias[i] = other.ideias[i];
    }
    return *this;
}

Brain::~Brain(){
    std::cout << "[Brain] Destructor called\n";
}

void Brain::setIdea(int index, const std::string &idea){
    if (index >= 0 && index <= 100)
        ideias[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index <= 100)
        return ideias[index];
    return "";
}