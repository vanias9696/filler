#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismus <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 16:01:42 by ismus             #+#    #+#              #
#    Updated: 2017/10/24 16:34:41 by ismus            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	ismus.filler

FUNC	=	first.c first_figure.c get_free_print.c move_to_player.c block.c try_block_hor.c ft_while_n_block.c

OBJ		=	$(FUNC:.c=.o)

CC		=	gcc

CFLAGS	=	-Wextra -Wall -Werror

all: $(NAME)

$(NAME): create $(OBJ)
	@$(CC) $(OBJ) -I /new_lib -L ./new_lib -lft -o $(NAME)
	@echo "\x1B[0;32m"$(NAME)" ready!"

create:
	@make -C new_lib/

$(OBJ): %.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

vis:
	@$(CC) $(CFLAGS) visual.c -I/new_lib/libft.h new_lib/libft.a -o Visual
	@echo "\x1B[0;32mvisual effect is ready!"

cvis:
	@rm -f Visual

clean:
	@make -C new_lib/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C new_lib/ fclean
	@rm -f $(NAME)

re: fclean all

.NOTPARALLEL: all $(NAME) re
