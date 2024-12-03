# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 18:20:56 by brandebr          #+#    #+#              #
#    Updated: 2024/12/03 18:48:43 by brandebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  btc

SRC = main.cpp BitcoinExchange.cpp

SRC_P = src/

OBJ_DIR = obj/

INC_DIR = inc/

HEADERS = $(addprefix $(INC_DIR),  BitcoinExchange.hpp)

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
	@valgrind --leak-check=full --track-origins=yes ./$(NAME) bdata.csv

totvalgrind: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) bdata.csv

sanitize: $(NAME)
	@-fsanitize=address ./$(NAME) bdata.csv 

run: $(NAME)
	@./$(NAME) bdata.csv

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -rf $(OBJ_DIR)
	/bin/rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
