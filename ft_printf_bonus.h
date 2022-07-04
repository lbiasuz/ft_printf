/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:56:31 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/07/03 23:21:35 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "libft/libft.h"
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				handle_print_conversion(va_list list, int converter);
char			*ft_utoa(unsigned int nb);
char			*ft_itob(unsigned int nb, char *base);
char			*ft_ultob(unsigned long long nb, char *base);
char			*alloc_char_or_string(va_list list, int type_flag);
unsigned int	long_long_size(unsigned long long nb, int base_len);
char			*get_flags(char *str);
char			*ft_precision_flag(char *str, char *flags);
char			*ft_blank_flag(char *str, char *flags);
char			*ft_sign_flag(char *str, char *flags);
char			*ft_hashtag_flag(char *str, char *flags);

#endif