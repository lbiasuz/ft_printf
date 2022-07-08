# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 22:11:38 by lbiasuz           #+#    #+#              #
#    Updated: 2022/07/08 17:54:42 by lbiasuz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

NAME	=	libftprintf.a

CFLAGS	=	-Wall -Wextra -Werror

SRC		=	ft_printf.c ft_converters.c

SRC_B	=	ft_printf_bonus.c ft_print_value_bonus.c ft_flags_bonus.c \
			ft_converters_bonus.c ft_lenght_flags_bonus.c

HEAD	=	ft_printf.h

OBJ		=	$(SRC:.c=.o)

OBJ_B	=	$(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a $(NAME)
	ar -r $(NAME) $(OBJ)

bonus: $(NAME_B)
	make OBJ="$(OBJ_B)"

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	make clean -C libft
	rm	-f $(NAME)

fclean: clean
	make fclean -C libft
	rm -rf $(OBJ) $(OBJ_B)

re: fclean all

.PHONY: bonus all clean fclean re