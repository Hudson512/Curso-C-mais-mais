/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:48:58 by hmateque          #+#    #+#             */
/*   Updated: 2025/04/17 12:22:34 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP   
# define BRAIN_HPPP

#include <iostream>

class Brain
{
private:
    std::string ideias[100];
public:
    Brain();
    Brain(const Brain &other);
    Brain& operator=(const Brain &other);
    ~Brain();

    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};



#endif