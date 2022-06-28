/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:56:31 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/06/27 23:40:41 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_flags{
	int	precision;
	int	min_size;
	int	left_pad;
	int	zeroes;
	int	blank_space;
	int	plus_sign;
	int	hashtag;
}	t_flags;

int		ft_printf(const char *str, ...);
int		handle_print_conversion(va_list list, int converter);
char	*ft_utoa(unsigned int nb);
char	*ft_itob(unsigned int nb, char *base);
char	*ft_ultob(unsigned long long nb, char *base);
char	*alloc_char_or_string(va_list list, int type_flag);

#endif