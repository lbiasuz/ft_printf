/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenght_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:44:55 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/07/05 00:48:24 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_lenght_flag(char *str, char *flags)
{
	unsigned long	min_lenght;
	unsigned long	str_len;
	char			*temp;
	char			*value;

	min_lenght = ft_find_number_flag(flags);
	str_len = ft_strlen(str);
	if (min_lenght > str_len)
	{
		min_lenght -= str_len;
		temp = (char *) ft_calloc((min_lenght + 1), sizeof(char));
		if (!temp)
			return (NULL);
		ft_memset(temp, ' ', min_lenght);
		if (ft_zeroes_flag(flags))
			ft_memset(temp, '0', min_lenght);
		if (ft_strchr(flags, '-'))
			value = ft_strjoin(str, temp);
		else
			value = ft_strjoin(temp, str);
		free(temp);
	}
	else
		value = str;
	return (value);
}

unsigned int	ft_zeroes_flag(char *str)
{
	return (ft_strchr(str, '0') && !ft_isdigit(*(ft_strchr(str, '0') - 1)));
}

int	ft_find_number_flag(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && i == 0)
			return (ft_atoi(str));
		else if (ft_isdigit(str[i]) && !ft_isdigit(str[i -1]))
			return (ft_atoi(str));
		i++;
	}
	return (0);
}
