#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 12:26:30 by hmateque          #+#    #+#              #
#    Updated: 2025/12/06 10:57:27 by hmateque         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=RPN

CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98

SRCS=main.cpp RPN.cpp
HEADERS=RPN.hpp
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