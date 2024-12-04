# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 17:54:05 by brandebr          #+#    #+#              #
#    Updated: 2024/12/04 11:26:17 by brandebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  PmergeMe

SRC = main.cpp PmergeMe.cpp

SRC_P = src/

OBJ_DIR = obj/

INC_DIR = inc/

HEADERS = $(addprefix $(INC_DIR),  PmergeMe.hpp)

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
	@valgrind --leak-check=full --track-origins=yes ./$(NAME) 81, 14, 63, 27, 50, 9, 71, 42, 38, 19

totvalgrind: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 33, 67, 12, 89, 45, 23, 78, 34, 56, 90


sanitize: $(NAME)
	-fsanitize=address ./$(NAME) 42, 17, 93, 8, 56, 21, 74, 37, 65, 12

run: $(NAME)
	./$(NAME)  3 5 9 7 4

shuff: $(NAME)
	./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "`

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -rf $(OBJ_DIR)
	/bin/rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
