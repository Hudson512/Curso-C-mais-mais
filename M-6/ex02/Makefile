#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 12:35:46 by hmateque          #+#    #+#              #
#    Updated: 2025/10/21 21:44:22 by hmateque         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = identify

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEARDERS = includes/A.hpp includes/B.hpp includes/C.hpp includes/Base.hpp
SRCS = functions.cpp main.cpp

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