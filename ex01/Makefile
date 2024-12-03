# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 14:17:19 by brandebr          #+#    #+#              #
#    Updated: 2024/12/02 19:07:58 by brandebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN 

SRC = main.cpp RPN.cpp

SRC_P = src/

OBJ_DIR = obj/

INC_DIR = inc/

HEADERS = $(addprefix $(INC_DIR),  RPN.hpp)

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -g

INCLUDES = -I$(INC_DIR)

all: Makefile $(NAME)

$(OBJ_DIR)%.o: $(SRC_P)%.cpp $(HEADERS) Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

valgrind: $(NAME)
	valgrind --leak-check=full --track-origins=yes ./$(NAME) "7 7 * 7 -" 

totvalgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) "1 2 * 2 / 2 * 2 4 - +"


sanitize: $(NAME)
	-fsanitize=address ./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"

run: $(NAME)
	./$(NAME) "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -" 

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -rf $(OBJ_DIR)
	/bin/rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
