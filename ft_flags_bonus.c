/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:38:45 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/07/08 17:43:08 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*get_flags(const char *str)
{
	unsigned int	lenght;

	lenght = 0;
	while (!ft_strchr("csidupxX%", str[lenght]))
	{
		if (!ft_strchr(" -+#.0123456789", str[lenght]))
			return (NULL);
		lenght++;
	}
	return (ft_substr(str, 0, lenght + 1));
}

char	*ft_precision_flag(char *str, char *flags)
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
			precision -= (str_len);
		temp = (char *) ft_calloc(precision + 1, sizeof(char));
		ft_memset(temp, '0', precision);
		value = ft_strjoin(temp, str);
		free(temp);
	}
	else
		value = str;
	return (value);
}

char	*ft_blank_flag(char *str, char *flags)
{
	char	*value;

	if (ft_strchr(flags, ' '))
		value = ft_strjoin(" ", str);
	else
		value = str;
	return (value);
}

char	*ft_sign_flag(char *str, char *flags)
{
	char			*value;
	unsigned int	is_digit;

	is_digit = (ft_strchr(flags, 'd') || ft_strchr(flags, 'i'));
	if (ft_strchr(flags, '+') && (is_digit) && ft_atoi(str) >= 0)
		value = ft_strjoin("+", str);
	else
		value = str;
	return (value);
}

char	*ft_hashtag_flag(char *str, char *flags)
{
	char			*value;
	unsigned int	is_hex;

	is_hex = (ft_strchr(flags, 'x') || ft_strchr(flags, 'X'));
	if (ft_strchr(flags, '#') && *str != '0' && is_hex)
	{
		value = ft_strjoin("0x", str);
		if (ft_strchr(flags, 'X'))
			value[1] = 'X';
	}
	else
		value = str;
	return (value);
}
