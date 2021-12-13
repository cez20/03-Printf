/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 09:54:07 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/12 23:24:57 by cemenjiv         ###   ########.fr       */
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
		printf("%ld\n", ft_strlen(*buf));
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

void	ft_putnbr_hex(size_t num, char *base, int *count, char **buf)
{
	size_t remainder;
	size_t i;
	
	remainder = 0;
	*buf = malloc(sizeof(char) * (hex_size(num) + 1)); 
	if (!*buf)
		return ;
	i = 0;
	*(*buf + i++) = '0';
	*(*buf + i++) = 'x';
	while (num != 0)
	{
		remainder = num % 16;
		if (remainder < 10)
			*(*buf + i++) = base[remainder];
		else
			*(*buf + i++) = base[remainder];
		num = num / 16;
	}
	*(*buf + i) = '\0'; // c'est cet element qui cause le still reachable memory
	(*count) += ft_strlen(*buf);
	write (1, *buf, ft_strlen(*buf));
}

size_t	hex_size(size_t nb)
{
	size_t count;
	
	while (nb != 0)
	{
		nb = nb / 16;
		count++;
	}
	return (count += 2);
}