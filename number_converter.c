/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:18:27 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/06/21 23:46:10 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	number_size(int nb, int base_len)
{
	unsigned int	i;

	i = 1;
	if (nb <= 0)
		i++;
	while (nb)
	{
		i++;
		nb = nb / base_len;
	}
	return (i);
}

static unsigned int	long_long_size(unsigned long long nb, int base_len)
{
	unsigned int	i;

	i = 1;
	if (nb <= 0)
		i++;
	while (nb)
	{
		i++;
		nb = nb / base_len;
	}
	return (i);
}

char	*ft_itob(int nb, char *base)
{
	char	*output;
	int		base_len;
	int		size;
	int		negative;

	negative = nb < 0;
	base_len = ft_strlen(base);
	size = number_size(nb, base_len);
	output = (char *) malloc(sizeof(char) * (size));
	if (!output)
		return (NULL);
	output[--size] = '\0';
	if (!nb)
		output[--size] = '0';
	while (nb)
	{
		output[--size] = base[(-negative + !negative) * (nb % base_len)];
		nb = nb / base_len;
	}
	if (negative)
		output[--size] = '-';
	return (output);
}

char	*ft_utoa(unsigned int nb)
{
	char	*output;
	int		size;

	size = long_long_size(nb, 10);
	output = (char *) malloc(sizeof(char) * (size + 1));
	if (!output)
		return (NULL);
	output[--size] = '\0';
	if (!nb)
		output[--size] = '0';
	while (nb)
	{
		output[--size] = ((nb % 10) + 48);
		nb = nb / 10;
	}
	return (output);
}

char	*ft_ultob(unsigned long long nb, char *base)
{
	char	*output;
	int		base_len;
	int		size;

	base_len = ft_strlen(base);
	size = long_long_size(nb, base_len);
	output = (char *) malloc(sizeof(char) * (size + 2));
	size = size + 2;
	if (!output)
		return (NULL);
	output[--size] = '\0';
	if (!nb)
		output[--size] = '0';
	while (size && nb)
	{
		output[--size] = base[nb % base_len];
		nb = nb / base_len;
	}
	output[--size] = 'x';
	output[--size] = '0';
	return (output);
}
