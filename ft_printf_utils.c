/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 09:54:07 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/07 09:54:11 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_new(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putnbr_new(int n, int *count)
{
	long long	nb;

	nb = (long long)n;
	if (nb < 0)
	{
		ft_putchar_new('-', count);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_new((nb / 10), count);
		nb = nb % 10;
	}
	if (nb >= 0 && nb < 10)
		ft_putchar_new((nb + '0'), count);
}

void	ft_putnbr_new1(int n, int *count)
{
	unsigned int	nb;

	nb = (unsigned int)n;
	if (nb >= 10)
	{
		ft_putnbr_new1((nb / 10), count);
		nb = nb % 10;
	}
	if (nb >= 0 && nb < 10)
		ft_putchar_new(nb + '0', count);
}

void	ft_putstr_new(char *s, int *count)
{
	if (!s)
	{
		write(1, "(null)", 6);
		(*count) += 6;
	}
	else
	{
		write(1, s, ft_strlen(s));
		(*count) += ft_strlen(s);
	}
}

void	ft_putnbr_hex(size_t num, size_t base_len, char *base, int *count)
{
	char	c;

	if (num >= base_len)
		ft_putnbr_hex(num / base_len, base_len, base, count);
	c = base[(num % base_len)];
	write(1, &c, 1);
	(*count)++;
}
