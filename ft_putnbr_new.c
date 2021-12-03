/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:59:24 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/02 14:51:37 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_new(int n, int *count)
{
	if (n < 0)
	{
		ft_putchar_new('-', count);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_new((n / 10), count);
		n = n % 10;
	}
	if (n >= 0 && n < 10)
		ft_putchar_new((n + '0'), count);
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
