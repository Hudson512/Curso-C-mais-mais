#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 00:01:56 by hmateque          #+#    #+#              #
#    Updated: 2025/11/18 00:04:08 by hmateque         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=easyfind

CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98

SRCS=main.cpp
HEADERS=easyfind.hpp
OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re