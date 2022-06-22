/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:18:27 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/06/20 20:15:18 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	number_size(int nb, int base_len)
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

unsigned int	number_size_pointer(unsigned long long nb, int base_len)
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

char	*itoh(int nb, char *base)
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

char	*ultoh(unsigned long long nb, char *base)
{
	char	*output;
	int		base_len;
	int		size;

	base_len = ft_strlen(base);
	size = number_size_pointer(nb, base_len);
	output = (char *) malloc(sizeof(char) * (size));
	if (!output)
		return (NULL);
	output[--size] = '\0';
	if (!nb)
		output[--size] = '0';
	while (size)
	{
		output[--size] = base[nb % base_len];
		nb = nb / base_len;
	}
	return (output);
}

char	*utoa(unsigned int nb)
{
	char	*output;
	int		size;

	size = number_size(nb, 10);
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
