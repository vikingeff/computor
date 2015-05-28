# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleger <gleger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/18 17:03:33 by gleger            #+#    #+#              #
#    Updated: 2015/05/28 13:03:47 by gleger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	computor

HEADERS = -I .

SRC =	main.cpp \
		Operator.class.cpp \

HPP =	computor.hpp \
		Operator.class.hpp \

OBJ =	$(SRC:.cpp=.o)
 
C++ =	clang++ -g -Wall -Wextra -Werror -O3

%.o:		%.cpp $(HPP)
	@echo "\033[1;36;m[Compiling $<]\t\033[0m: " | tr -d '\n'
	$(C++) -c $< $(HEADERS)

all:		$(NAME)

$(NAME):	$(OBJ) $(HPP)
	@echo "\033[1;35;m[Linking] \t\t\033[0m: " | tr -d '\n'
	$(C++) -o $@ $(OBJ)
	@echo "\033[1;32;m[Success] \t\t\t\033[0m"

clean:
	@echo "\033[0;33;m[Cleaning] \t\t\033[0m: " | tr -d '\n'
	rm -f $(OBJ)

fclean:		clean
	@echo "\033[0;31;m[Deleting $(NAME)] \t\033[0m: " | tr -d '\n'
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
