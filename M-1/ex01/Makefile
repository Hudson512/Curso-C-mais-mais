# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 09:08:20 by hmateque          #+#    #+#              #
#    Updated: 2025/01/29 12:09:48 by hmateque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombieHorde
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp \
		zombieHorde.cpp \
		Zombie.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re