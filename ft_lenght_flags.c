/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenght_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:44:55 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/07/05 02:11:54 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_lenght_flag(char *str, char *flags)
{
	unsigned long	min_lenght;
	unsigned long	str_len;
	char*			temp;
	char*			value;

	str_len = ft_strlen(str);
	min_lenght = ft_find_number_flag(flags);
	value = NULL;
	if (min_lenght > str_len)
	{
		if (min_lenght <= str_len)
			min_lenght = str_len;
		else
			min_lenght -= (str_len);
		temp = (char *) ft_calloc(min_lenght + 1, sizeof(char));
		if (ft_zeroes_flag(flags))
			ft_memset(temp, '0', min_lenght);
		else
			ft_memset(temp, ' ', min_lenght);
		if (ft_strchr(flags, '-'))
			value = ft_strjoin(str, temp);
		else
			value = ft_strjoin(temp, str);
		free(temp);
	}
	return (value);
}

unsigned int	ft_zeroes_flag(char *str)
{
	return (ft_strchr(str, '0') && !ft_isdigit(*(ft_strchr(str, '0') - 1)));
}

int	ft_find_number_flag(char *str)
{
	while (*(str++))
	{
		if (ft_isdigit(*str) && !ft_isdigit(*(str - 1)))
			return (ft_atoi(str));
	}
	return (0);
}