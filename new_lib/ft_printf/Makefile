#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismus <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 16:34:22 by ismus             #+#    #+#              #
#    Updated: 2017/11/28 16:08:40 by ismus            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libftprintf.a

FUNC	=	ft_printf.c data_type.c unicode.c one_two_byte.c three_byte.c	\
			four_byte.c modif_else.c modif_ls.c modif_zjl.c flags.c 		\
			type_s.c acc_bytes.c modif_p.c ft_n_and_s.c type_c.c			\
			all_param.c flags_oux.c modif_t.c flags_mid.c type_s0.c

OBJS	=	./

OBJ		=	$(addprefix $(OBJS), $(FUNC:.c=.o))

FLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -c $(FUNC)
	@ar rc $(NAME) $(OBJ)

$(OBJS)/%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -f libft/obj/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -f libft/libft.a

re: fclean all
