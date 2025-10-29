/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:11:21 by hmateque          #+#    #+#             */
/*   Updated: 2025/10/29 10:51:44 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ITER_HPP
# define ITER_HPP
#include <cstddef>

template <typename T, typename F> void iter(T *arr, const size_t len, F func)
{
    for (size_t i = 0; i < len; i++)
        func(arr[i]);
}

template <typename T, typename F> void iter(T const *arr, const size_t len, F func)
{
    for (size_t i = 0; i < len; i++)
        func(arr[i]);
}  


#endif