/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 01:06:32 by hmateque          #+#    #+#             */
/*   Updated: 2025/11/20 17:09:37 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned int n) : _max(n) {}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->_max = other._max;
        this->_data = other._data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (_data.size() >= _max)
        throw std::runtime_error("Error: Span is full");
    _data.push_back(n);
}

int Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw std::runtime_error("Error: Not enough numbers for a span");

    std::vector<int> tmp = _data;
    std::sort(tmp.begin(), tmp.end());

    int minSpan = std::numeric_limits<int>::max();

    for (size_t i = 0; i < tmp.size() - 1; i++)
    {
        int diff = tmp[i + 1] - tmp[i];
        if (diff < minSpan)
            minSpan = diff;
    }

    return minSpan;
}

int Span::longestSpan() const
{
    if (_data.size() < 2)
        throw std::runtime_error("Error: Not enough numbers for a span");

    int minVal = *std::min_element(_data.begin(), _data.end());
    int maxVal = *std::max_element(_data.begin(), _data.end());

    return maxVal - minVal;
}
