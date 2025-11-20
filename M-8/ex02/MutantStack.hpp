/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    MutantStack.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:34:22 by hmateque          #+#    #+#             */
/*   Updated: 2025/11/20 18:38:25 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() {}
    MutantStack(const MutantStack &other) : std::stack<T>(other) {}
    MutantStack &operator=(const MutantStack &other)
    {
        if (this != &other)
            std::stack<T>::operator=(other);
        return *this;
    }
    ~MutantStack() {}

    // Iterator types
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // begin/end iterators
    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end(); }

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end()   const { return this->c.end(); }

    // reverse iterators
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend()   { return this->c.rend(); }

    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend()   const { return this->c.rend(); }
};

#endif
