# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 12:15:35 by hmateque          #+#    #+#              #
#    Updated: 2025/01/29 12:16:52 by hmateque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re