#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 12:26:30 by hmateque          #+#    #+#              #
#    Updated: 2025/12/03 17:28:55 by hmateque         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=btc

CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98

SRCS=main.cpp BitcoinExchange.cpp
HEADERS=BitcoinExchange.hpp
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