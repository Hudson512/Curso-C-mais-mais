/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:47:25 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/30 11:30:19 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T> class Array
{
private:
    T* _array;
    unsigned int _size;
    
public:
    Array() : _array(NULL), _size(0) {};
    Array(unsigned int n) : _array(new T[n]()), _size(n) {};
    Array(const Array &other) : _array(NULL), _size(0)
    {
        *this = other;
    }

    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] this->_array;
            this->_size = other._size;
            if (this->_size > 0)
            {
                this->_array = new T[this->_size];
                for (unsigned int i = 0; i < this->_size; i++)
                {
                    this->_array[i] = other._array[i];
                }
            }
            else
            {
                this->_array = NULL;
            }
        }
        return *this;
    }
    ~Array()
    {
        delete[] _array;
    }

    T& operator[](unsigned int index)
    {
        if (index >= this->_size)
            throw std::out_of_range("Index fora do range do array");
        return this->_array[index];
    }
    const T& operator[](unsigned int index) const
    {
        if (index >= this->_size)
            throw std::out_of_range("Index fora do range do array");
        return this->_array[index];
    }

    unsigned int size() const 
    {
        return this->_size;
    }
    
};



#endif