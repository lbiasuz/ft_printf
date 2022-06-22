/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:26:37 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/06/21 23:44:48 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_print_conversion(va_list args, int cflag)
{
	char	*value;
	int		len;

	value = NULL;
	if (cflag == 'd' || cflag == 'i')
		value = ft_itoa(va_arg(args, int));
	else if (cflag == 'u')
		value = ft_utoa(va_arg(args, unsigned int));
	else if (cflag == 'x')
		value = ft_itob(va_arg(args, int), "0123456789abcdef");
	else if (cflag == 'X')
		value = ft_itob(va_arg(args, int), "0123456789ABCDEF");
	else if (cflag == 'p')
		value = ft_ultob(va_arg(args, unsigned long long), "0123456789abcdef");
	else if (cflag == 's' || cflag == 'c')
		value = alloc_char_or_string(args, cflag);
	else if (cflag == '%')
		value = ft_strdup("%");
	len = ft_strlen(value);
	ft_putstr_fd(value, 1);
	if (value != NULL)
		free(value);
	return (len);
}

char	*alloc_char_or_string(va_list list, int type_flag)
{
	char	*value;

	if (type_flag == 'c')
	{
		value = malloc(sizeof(char) * 2);
		value[0] = va_arg(list, int);
		value[1] = 0;
	}
	else if (type_flag == 's')
		value = ft_strdup(va_arg(list, char *));
	return (value);
}
