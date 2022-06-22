# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 22:11:38 by lbiasuz           #+#    #+#              #
#    Updated: 2022/06/22 20:42:30 by lbiasuz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CFLAGS	=	-Wall -Wextra -Werror

SRC		=	ft_printf.c ft_converters.c

HEAD	=	ft_printf.h

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	ar rcT $(NAME) $(OBJ) libft/libft.a
	
%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	make clean -C libft
	rm	-f $(NAME)

fclean: clean
	make fclean -C libft
	rm -rf $(OBJ)

re: fclean all

.PHONY: bonus all clean fclean re