/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:04:29 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/07/04 22:58:11 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "stdio.h"

int	ft_printf(const char *str, ...)
{
	int		printed;
	char	*value;
	char	*flags;
	va_list	args;

	va_start(args, str);
	printed = 0;
	while (*str)
	{
		if (*str == '%')
		{
			flags = get_flags(str + 1);
			value = get_converted_value(args, *(str + ft_strlen(flags)));
			printed += print_value(value, flags) - 1;
			str += ft_strlen(flags);
			free(flags);
		}
		else
			ft_putchar_fd(*str, 1);
		printed++;
		str++;
	}
	va_end(args);
	return (printed);
}

char	*get_converted_value(va_list args, int cflag)
{
	char	*value;

	value = NULL;
	if (cflag == 'd' || cflag == 'i')
		value = ft_itoa(va_arg(args, int));
	else if (cflag == 'u')
		value = ft_utoa(va_arg(args, unsigned int));
	else if (cflag == 'x')
		value = ft_itob(va_arg(args, unsigned int), "0123456789abcdef");
	else if (cflag == 'X')
		value = ft_itob(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (cflag == 'p')
		value = ft_ultob(va_arg(args, unsigned long long), "0123456789abcdef");
	else if (cflag == 's' || cflag == 'c')
		value = alloc_char_or_string(args, cflag);
	else
		value = ft_strdup("%");
	return (value);
}

char	*alloc_char_or_string(va_list list, int type_flag)
{
	char	*value;

	value = NULL;
	if (type_flag == 'c')
	{
		value = malloc(sizeof(char) * 2);
		value[0] = va_arg(list, int);
		value[1] = 0;
	}
	else if (type_flag == 's')
	{
		value = va_arg(list, char *);
		if (!value)
			value = ft_strdup("(null)");
		else
			value = ft_strdup(value);
	}
	return (value);
}
