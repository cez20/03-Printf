/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 09:54:07 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/09 16:17:34 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_new(char c, int *count, char **buf)
{
	*buf = malloc(1 * sizeof(char));
	if (!buf)
		return ;
	*buf[0] = c;
	write(1, *buf, 1);
	(*count)++;
}

void	ft_putstr_new(char *s, int *count, char **buf)
{
	if (!s)
	{
		write(1, "(null)", 6);
		(*count) += 6;
	}
	else
	{
		*buf = ft_strdup(s);
		write(1, *buf, ft_strlen(*buf));
		(*count) += ft_strlen(*buf);
	}
}

/*void	ft_putnbr_new(int n, int *count, char **buf)
{
	long long	nb;

	nb = (long long)n;
	if (nb < 0)
	{
		ft_putchar_new('-', count, buf);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_new((nb / 10), count, buf);
		nb = nb % 10;
	}
	if (nb >= 0 && nb < 10)
		ft_putchar_new((nb + '0'), count, buf);
}

void	ft_putnbr_new1(int n, int *count, char **buf)
{
	unsigned int	nb;

	nb = (unsigned int)n;
	if (nb >= 10)
	{
		ft_putnbr_new1((nb / 10), count, buf);
		nb = nb % 10;
	}
	if (nb >= 0 && nb < 10)
		ft_putchar_new(nb + '0', count, buf);
}*/

void	ft_putnbr_hex(unsigned long long num, char *base, int *count, char **buf)
{
	int size;
	int remainder;
	int i;

	size = nb_length(num);
	*buf = malloc((size) * sizeof(char));
	*buf[0] = '0';
	*buf[1] = 'x';
	i = 2;
	while (num != 0)
	{
		remainder = num % 16;
		if (remainder < 10)
			*buf[i++] = base[remainder];
		else
			*buf[i++] = base[remainder];
		num = num / 16;
	}
	*buf[size] = '\0';

	write (1, *buf, ft_strlen(*buf));
	(*count) += ft_strlen(*buf);
}
