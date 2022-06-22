/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:56:33 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/06/21 23:28:31 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		printed;
	va_list	args;

	va_start(args, str);
	printed = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			printed += handle_print_conversion(args, *str);
			str++;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			printed++;
			str++;
		}
	}
	va_end(args);
	return (printed);
}

/*
	%: putchar
	c: putchar
	s: putstr
	p: putnbr + 0x
	d: putnbr
	i: putnbr
	u: putnbr
	x: putnbr variable base
	X: putnbr variable base
*/