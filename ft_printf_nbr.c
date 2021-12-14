/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:17:59 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/13 19:25:23 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_new(size_t n, int *count, char **buf)
{
	int			length;
	int			i;
	long long	nb;

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

void	ft_putnbr_new1(int n, int *count, char **buf)
{
	int				length;
	int				i;
	unsigned int	nb;

	nb = (unsigned int)n;
	length = nb_length1(nb);
	*buf = malloc((length + 1) * sizeof(char));
	if (!*buf)
		return ;
	i = (length - 1);
	while (nb >= 10)
	{
		*(*buf + i--) = '0' + (nb % 10);
		nb = nb / 10;
	}
	*(*buf + i) = '0' + nb;
	*(*buf + length) = '\0';
	write(1, *buf, ft_strlen(*buf));
	(*count) += ft_strlen(*buf);
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

int	nb_length1(unsigned int n)
{
	int	length;

	length = 0;
	while (n >= 10)
	{
		n = n / 10;
		length++;
	}	
	length++;
	return (length);
}
