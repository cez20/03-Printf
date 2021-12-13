/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 09:54:07 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/13 02:11:02 by cemenjiv         ###   ########.fr       */
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

void	ft_putnbr_new(int n, int *count, char **buf)
{
	int length;
	int i;
	long long nb;
	
	nb = (long long)n;
	length = nb_length(nb);
	*buf = malloc((length + 1) * sizeof(char));
	if (nb < 0)
	{
		*(*buf + 0) = '-';
		nb = -nb;
	}
	i = (length - 1);
	while (nb >= 10)
	{
		*(*buf + i--) = '0' + (nb % 10);
		nb = nb / 10;
	}
	if (nb >= 0 && nb < 10)
		*(*buf + i) = '0' + nb;
	*(*buf + length) = '\0';
	write(1, *buf, ft_strlen(*buf));
	(*count) += ft_strlen(*buf);
}

/*void	ft_putnbr_new1(int n, int *count, char **buf)
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
	size_t	size;
	size_t	remainder;
	size_t	i;
	
	if (num == 0)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	size = hex_size(num);
	*buf = malloc(sizeof(char) * (size + 1)); 
	if (!*buf)
		return ;
	*(*buf + 0) = '0';
	*(*buf + 1) = 'x';
	i = size - 1;
	remainder = 0;
	while (num != 0)
	{
		remainder = num % 16;
		*(*buf + i--) = base[remainder];
		num = num / 16;
	}
	*(*buf + size) = '\0'; 
	(*count) += ft_strlen(*buf);
	write (1, *buf, ft_strlen(*buf));
}

size_t	hex_size(size_t nb)
{
	size_t count;
	
	count = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		count++;
	}
	return (count += 2);
}

int	nb_length(long long n)
{
	int	length;

	length = 0;
	if (n < 0)
	{
		n = -n;
		length++;
	}
	while (n >= 10)
	{
		n = n / 10;
		length++;
	}	
	if (n >= 0 && n < 10)
		length++;
	return (length);
}