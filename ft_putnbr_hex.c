/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:42:54 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/03 17:38:08 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_addr_hex(unsigned long nbr, int *count)
{
	int				i;
	int				j;
	unsigned long	remainder;
	char			hexadecimal[100];

	ft_putchar_new('0', count);
	ft_putchar_new('x', count);
	remainder = 0;
	j = 0;
	if (nbr == 0)
		ft_putchar_new('0', count);
	while (nbr != 0)
	{
		remainder = nbr % 16;
		if (remainder < 10)
			hexadecimal[j++] = 48 + remainder;
		else
			hexadecimal[j++] = ft_tolower(55 + remainder);
		nbr = nbr / 16;
		(*count)++;
	}
	i = j - 1;
	while (i >= 0)
		write (1, &hexadecimal[i--], 1);
}

void	ft_putnbr_hex_low(long long nbr, int *count)
{
	int			i;
	int			j;
	long long	remainder;
	char		hexadecimal[100];

	remainder = 0;
	j = 0;
	if (nbr == 0)
		ft_putchar_new('0', count);
	while (nbr != 0)
	{
		remainder = nbr % 16;
		if (remainder < 10)
			hexadecimal[j++] = 48 + remainder;
		else
			hexadecimal[j++] = ft_tolower(55 + remainder);
		nbr = nbr / 16;
		(*count)++;
	}
	i = j - 1;
	while (i >= 0)
		write (1, &hexadecimal[i--], 1);
}

void	ft_putnbr_hex_upp(long long nbr, int *count)
{
	int			i;
	int			j;
	long long	remainder;
	char		hexadecimal[100];

	remainder = 0;
	j = 0;
	if (nbr == 0)
		ft_putchar_new('0', count);
	while (nbr != 0)
	{
		remainder = nbr % 16;
		if (remainder < 10)
			hexadecimal[j++] = 48 + remainder;
		else
			hexadecimal[j++] = 55 + remainder;
		nbr = nbr / 16;
		(*count)++;
	}
	i = j - 1;
	while (i >= 0)
		write (1, &hexadecimal[i--], 1);
}
