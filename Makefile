# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 18:53:09 by anzarago          #+#    #+#              #
#    Updated: 2025/05/15 20:51:17 by anzarago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Werror -Wall -Wextra
MAKE = make -sC

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC_DIR = src/
OBJ_DIR = objs/

SRC =	$(SRC_DIR)main.c\
		$(SRC_DIR)push.c\
		$(SRC_DIR)reverse_rotate.c\
		$(SRC_DIR)rotate.c\
		$(SRC_DIR)check.c\
		$(SRC_DIR)list.c\
		$(SRC_DIR)sort.c\
		$(SRC_DIR)utils.c\
		$(SRC_DIR)swap.c

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(LIBFT) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "ok \n "

$(LIBFT):
	$(MAKE) $(LIBFT_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "program ready \n"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "ok \n"

clean:
	@rm -f $(OBJ)
	@$(MAKE) $(LIBFT_DIR) clean
	@echo "clean"

fclean: clean
	@rm -f $(NAME) 
	@$(MAKE) $(LIBFT_DIR) fclean
	@echo "clean"

re: clean fclean all

.PHONY: re all clean fclean