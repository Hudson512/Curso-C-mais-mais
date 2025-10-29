#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 09:16:24 by hmateque          #+#    #+#              #
#    Updated: 2025/10/29 10:10:41 by hmateque         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME=iter

CXX=c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

HEADERS= iter.hpp
SRCS= main.cpp
OBJ=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

