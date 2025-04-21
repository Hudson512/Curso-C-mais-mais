# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 10:01:40 by hmateque          #+#    #+#              #
#    Updated: 2025/04/17 12:05:39 by hmateque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Polymorphism
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp\
		srcs/Animal.cpp\
		srcs/Cat.cpp\
		srcs/Dog.cpp\
		srcs/Brain.cpp\
		
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re