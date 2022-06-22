# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 22:11:38 by lbiasuz           #+#    #+#              #
#    Updated: 2022/05/30 23:44:50 by lbiasuz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CFLAGS	=	-Wall -Wextra -Werror -g3

SRC		=	ft_printf.c

HEAD	=	ft_printf.h

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	ar rcT $(NAME) $(OBJ) libft/libft.a
	
%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm	-f $(NAME)

fclean: clean
	make fclean -C libft
	rm -rf $(OBJ)

re: fclean all

.PHONY: bonus all clean fclean re