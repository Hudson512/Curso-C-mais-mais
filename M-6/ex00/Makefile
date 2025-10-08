#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 12:35:46 by hmateque          #+#    #+#              #
#    Updated: 2025/10/08 12:40:58 by hmateque         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = convert

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEARDERS = ScalarConverter.hpp
SRCS = ScalarConverter.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEARDERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re