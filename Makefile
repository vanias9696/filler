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

NAME	=	filler.ismus

FUNC	=	first.c


OBJ		=	$(FUNC:.c=.o)

CC		=	gcc

CFLAGS	=	-Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C new_lib/
	@$(CC) $(CFLAGS) -c $(FUNC)
	@$(CC) $(CFLAGS) $(OBJ) -I/new_lib/libft.h new_lib/libft.a -o $(NAME)

$(OBJ): %.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.NOTPARALLEL: all $(NAME) re
