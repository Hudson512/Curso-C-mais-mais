#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 10:54:33 by hmateque          #+#    #+#              #
#    Updated: 2025/10/30 10:58:28 by hmateque         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=array

CXX=c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

HEADERS= Array.hpp
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