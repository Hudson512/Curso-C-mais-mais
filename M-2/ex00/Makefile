# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 08:31:01 by hmateque          #+#    #+#              #
#    Updated: 2025/02/11 08:34:43 by hmateque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myFirstClassOrthodox
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp\
		Fixed.cpp
		
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
