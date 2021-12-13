/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:56:00 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/13 01:56:21 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flag(va_list va_list1, const char *str, int *count, char **buf)
{
	if (*str == 'c')
		ft_putchar_new (va_arg(va_list1, int), count, buf);
	else if (*str == 's')
		ft_putstr_new (va_arg(va_list1, char *), count, buf);
	else if (*str == 'p')
		ft_putnbr_hex (va_arg(va_list1, size_t), LOW_HEX, count, buf);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr_new(va_arg(va_list1, long long), count, buf);
	/*else if (*str == 'u')
		ft_putnbr_new1(va_arg(va_list1, int), count, buf);
	else if (*str == 'x')
		ft_putnbr_hex(va_arg(va_list1, unsigned), LOW_HEX, count);
	else if (*str == 'X')
		ft_putnbr_hex(va_arg(va_list1, unsigned), UP_HEX, count);
	else if (*str == '%')
		ft_putchar_new('%', count, &buf);*/
	else
	{
		ft_putchar_new('%', count, buf);
		ft_putchar_new(*str, count, buf);
	}
}

int	ft_printf(const char *str, ...)
{
	int			count;
	char		*buffer;
	va_list		va_list1;

	va_start(va_list1, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			print_flag(va_list1, str, &count, &buffer);
		}
		else
			ft_putchar_new(*str, &count, &buffer);
		str++;
		free(buffer); 
		buffer = NULL; 
	}
	va_end(va_list1);
	return (count);
}
