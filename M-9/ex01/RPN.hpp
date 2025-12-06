/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:46:19 by hmateque          #+#    #+#             */
/*   Updated: 2025/12/06 12:28:22 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <limits>


class RPN
{
    private:
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);

    public:
        RPN();
        ~RPN();

        static int evaluate(const std::string &expression);
};



#endif