# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 22:11:38 by lbiasuz           #+#    #+#              #
#    Updated: 2022/07/05 00:43:48 by lbiasuz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

NAME	=	libftprintf.a

NAME_B	=	libftprintf_bonus.a

CFLAGS	=	-Wall -Wextra -Werror

SRC		=	ft_printf.c ft_converters.c

SRC_B	=	ft_printf_bonus.c ft_print_value_bonus.c ft_flags_bonus.c \
			ft_converters_bonus.c ft_lenght_flags_bonus.c

HEAD	=	ft_printf.h

HEAD_B	=	ft_printf.h

OBJ		=	$(SRC:.c=.o)

OBJ_B	=	$(SRC_B:.c=.o)

all: $(NAME)

bonus: $(NAME_B)

$(NAME): $(OBJ)
	make -C libft
	ar rcT $(NAME) $(OBJ) libft/libft.a

$(NAME_B): $(OBJ_B)
	make -C libft
	ar rcT $(NAME_B) $(OBJ_B) libft/libft.a
	
%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	make clean -C libft
	rm	-f $(NAME) $(NAME_B)

fclean: clean
	make fclean -C libft
	rm -rf $(OBJ) $(OBJ_B)

re: fclean all

.PHONY: bonus all clean fclean re