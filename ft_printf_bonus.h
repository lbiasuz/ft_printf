/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:56:31 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/07/03 23:40:10 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "libft/libft.h"
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				ft_find_number_flag(char *str);
unsigned int	long_long_size(unsigned long long nb, int base_len);
char			*ft_utoa(unsigned int nb);
char			*ft_itob(unsigned int nb, char *base);
char			*ft_ultob(unsigned long long nb, char *base);
char			*get_converted_value(va_list list, int converter);
char			*alloc_char_or_string(va_list list, int type_flag);
char			*get_flags(const char *str);
char			*ft_precision_flag(char *str, char *flags);
char			*ft_blank_flag(char *str, char *flags);
char			*ft_sign_flag(char *str, char *flags);
char			*ft_hashtag_flag(char *str, char *flags);
unsigned int	ft_zeroes_flag(char *str);
char			*ft_lenght_flag(char *str, char *flags);
char			*pass_value(char *value, char *temp);
int				print_value(char *value, char *flags);

#endif