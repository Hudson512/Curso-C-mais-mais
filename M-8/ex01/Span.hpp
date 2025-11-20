/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 01:03:20 by hmateque          #+#    #+#             */
/*   Updated: 2025/11/20 18:18:14 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span
{
private:
    unsigned int _max;
    std::vector<int> _data;

public:
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int n);

    template <typename It> void addRange(It begin, It end)
    {
        unsigned int distance = 0;
        for (It tmp = begin; tmp != end; ++tmp)
            distance++;

        if (_data.size() + distance > _max)
            throw std::runtime_error("Error: Not enough space to add range");

        _data.insert(_data.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;
};

#endif
