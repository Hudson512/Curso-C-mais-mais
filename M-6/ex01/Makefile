#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 12:35:46 by hmateque          #+#    #+#              #
#    Updated: 2025/10/20 12:05:32 by hmateque         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = serializer

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEARDERS = Serializer.hpp
SRCS = Serializer.cpp main.cpp

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