/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 00:04:21 by hmateque          #+#    #+#             */
/*   Updated: 2025/11/18 00:49:22 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>

template <typename T> int easyfind(const T &container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end()) {
        return *it;
    } else {
        throw std::runtime_error("Value not found in container");
    }
}

#endif