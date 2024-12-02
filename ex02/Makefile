# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 17:54:05 by brandebr          #+#    #+#              #
#    Updated: 2024/12/02 17:55:46 by brandebr         ###   ########.fr        #
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
	@valgrind --leak-check=full --track-origins=yes ./$(NAME)

totvalgrind: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)


sanitize: $(NAME)
	-fsanitize=address ./$(NAME)

run: $(NAME)
	./$(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -rf $(OBJ_DIR)
	/bin/rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
