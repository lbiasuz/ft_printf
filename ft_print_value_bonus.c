/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_value_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:12:39 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/07/09 23:10:30 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_value(char *value, char *flags, int converter)
{
	char	*temp;
	int		lenght;

	temp = ft_hashtag_flag(value, flags);
	value = pass_value(value, temp);
	temp = ft_sign_flag(value, flags);
	value = pass_value(value, temp);
	temp = ft_blank_flag(value, flags, converter);
	value = pass_value(value, temp);
	temp = ft_precision_flag(value, flags);
	value = pass_value(value, temp);
	temp = ft_lenght_flag(value, flags);
	value = pass_value(value, temp);
	ft_putstr_fd(value, 1);
	if (*value == 0 && converter == 'c')
		ft_putchar_fd(0, 1);
	lenght = (*value == 0 && converter == 'c') + ft_strlen(value);
	free(value);
	return (lenght);
}

char	*pass_value(char *value, char *temp)
{
	if (value != temp)
	{
		free(value);
		value = temp;
	}
	return (value);
}
