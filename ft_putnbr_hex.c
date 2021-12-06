/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:42:54 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/06 16:16:19 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(size_t num, size_t base_len, char *base, int *count)
{
	char	c;

	if (num >= base_len)
		ft_putnbr_hex(num / base_len, base_len, base, count);
	c = base[(num % base_len)];
	write(1, &c, 1);
	(*count)++;
}

void	ft_putnbr_hex1(unsigned num, unsigned base_len, char *base, int *count)
{
	char	c;

	if (num >= base_len)
		ft_putnbr_hex(num / base_len, base_len, base, count);
	c = base[(num % base_len)];
	write(1, &c, 1);
	(*count)++;
}
