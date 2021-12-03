/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:56:00 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/03 17:37:59 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flag(va_list va_list1, const char *str, int *count)
{
	if (*str == 'c')
		ft_putchar_new (va_arg(va_list1, int), count);
	else if (*str == 's')
		ft_putstr_new (va_arg(va_list1, char *), count);
	else if (*str == 'p')
		ft_putnbr_addr_hex (va_arg(va_list1, unsigned long), count);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr_new(va_arg(va_list1, int), count);
	else if (*str == 'u')
		ft_putnbr_new1(va_arg(va_list1, int), count);
	else if (*str == 'x')
		ft_putnbr_hex_low (va_arg(va_list1, long long), count);
	else if (*str == 'X')
		ft_putnbr_hex_upp(va_arg(va_list1, long long), count);
	else if (*str == '%')
		ft_putchar_new('%', count);
	else
	{
		ft_putchar_new('%', count);
		ft_putchar_new(*str, count);
	}
}

int	ft_printf(const char *str, ...)
{
	int			count;
	va_list		va_list1;

	va_start(va_list1, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			print_flag(va_list1, str, &count);
		}
		else
			ft_putchar_new(*str, &count);
		str++;
	}
	va_end(va_list1);
	return (count);
}
