/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:56:31 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/06/20 19:45:46 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CASTS "cspdiuxX%"; 

int		ft_printf(const char *str, ...);
int		handle_print(va_list list, int converter);
char	*itoh(int nb, char *base);
char	*utoa(unsigned int nb);
char	*ultoh(unsigned long long nb, char *base);
char	*atoa(va_list list, int type_flag);

#endif