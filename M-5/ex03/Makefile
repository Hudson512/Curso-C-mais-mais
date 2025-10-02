# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 09:29:15 by hmateque          #+#    #+#              #
#    Updated: 2025/07/15 14:54:32 by hmateque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Intern.exe

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = ./includes/AForm.hpp ./includes/Bureaucrat.hpp ./includes/PresidentialPardonForm.hpp ./includes/RobotomyRequestForm.hpp ./includes/ShrubberyCreationForm.hpp ./includes/Intern.hpp
SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

