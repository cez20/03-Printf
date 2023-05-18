/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:01:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/17 23:34:14 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(size_t num, char *base, int *count, char **buf)
{
	int	i;

	*buf = malloc(sizeof(char) * (hex_size(num) + 3));
	if (!*buf)
		return ;
	i = 0;
	*(*buf + i++) = '0';
	*(*buf + i++) = 'x';
	ft_putnbr_recurs(num, base, buf, &i);
	*(*buf + i) = '\0';
	(*count) += ft_strlen(*buf);
	write (1, *buf, ft_strlen(*buf));
}

void	ft_putnbr_hex1(size_t num, char *base, int *count, char **buf)
{
	int	i;

	*buf = malloc(sizeof(char) * (hex_size(num) + 1));
	if (!*buf)
		return ;
	i = 0;
	ft_putnbr_recurs(num, base, buf, &i);
	*(*buf + i) = '\0';
	(*count) += ft_strlen(*buf);
	write (1, *buf, ft_strlen(*buf));
}

size_t	hex_size(size_t nb)
{
	size_t	count;

	count = 0;
	if (nb == 0)
		count++;
	while (nb != 0)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}

void	ft_putnbr_recurs(size_t num, char *base, char **buf, int *i)
{
	if (num >= 16)
		ft_putnbr_recurs(num / 16, base, buf, i);
	*(*buf + (*i)++) = base[num % 16];
}
