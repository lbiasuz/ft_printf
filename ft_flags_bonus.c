/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:38:45 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/07/01 00:01:17 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"


t_flags	*get_flags(char *str)
{
	t_flags	*flags;

	flags = (t_flags *) malloc(sizeof(t_flags));
	while(*str && !ft_strchr("csdiuxX%", *str))
	{
		if (*str == ' ')
			flags->blank_space = 1;
		if (*str == '+')
			flags->sign = 1;
		if (*str == '-')
			flags->left_pad = 1;
		if (*str == '#')
			flags->hashtag = 1;
		if (*str == '0' && ft_isdigit(*(str++)))
			flags->zeroes = 1;
		if (ft_isdigit(*str))
		{
			flags->min_size = ft_atoi(str);
			str += long_long_size(flags->min_size, 10) - 1;
		}
		if (*str == '.' && ft_isdigit(*(str + 1)))
		{
			flags->precision = ft_atoi((str + 1));
			str += long_long_size(flags->precision, 10) - 1;
		}
		str++;
	}
	return (flags);
}

char *ft_precision_flag(char *str, char *flags)
{
	unsigned int	precision;
	unsigned int	str_len;
	char			*value;
	char			*temp;

	if (ft_strchr(flags, '.') && ft_isdigit(*(ft_strchr(flags, '.') + 1)))
	{
		str_len = ft_strlen(str);
		precision = ft_atoi(ft_strchr(flags, '.') + 1);
		if (precision <= str_len)
			precision = str_len;
		else
			precision -= str_len;
		temp = (char *) malloc(sizeof(char) * (precision));
		ft_memset(temp, '0', precision);
		temp[precision - 1] = 0;
		value = ft_strjoin(temp, str);
		free(temp);
	}
	else
		value = str;
	return (value);
}