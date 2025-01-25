# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 12:15:20 by hmateque          #+#    #+#              #
#    Updated: 2025/01/16 12:17:19 by hmateque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = account
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	srcs/Account.cpp \
		srcs/tests.cpp \
		
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
