/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:56:00 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/08 11:54:55 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flag(va_list va_list1, const char *str, int *count, char *buf)
{
	if (*str == 'c')
		ft_putchar_new (va_arg(va_list1, int), count, &buf);
	/*else if (*str == 's')
		ft_putstr_new (va_arg(va_list1, char *), count);
	else if (*str == 'p')
	{
		ft_putstr_new("0x", count);
		ft_putnbr_hex(va_arg(va_list1, size_t), LOW_HEX, count);
	}
	else if (*str == 'd' || *str == 'i')
		ft_putnbr_new(va_arg(va_list1, int), count);
	else if (*str == 'u')
		ft_putnbr_new1(va_arg(va_list1, int), count);
	else if (*str == 'x')
		ft_putnbr_hex(va_arg(va_list1, unsigned), LOW_HEX, count);
	else if (*str == 'X')
		ft_putnbr_hex(va_arg(va_list1, unsigned), UP_HEX, count);
	else if (*str == '%')
		ft_putchar_new('%', count);
	else
	{
		ft_putchar_new('%', count);
		ft_putchar_new(*str, count);
	}*/
}

int	ft_printf(const char *str, ...)
{
	int			count;
	char		*buffer;
	va_list		va_list1;

	buffer = NULL;
	va_start(va_list1, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			print_flag(va_list1, str, &count, buffer);
		}
		else
			ft_putchar_new(*str, &count, &buffer);
		str++;
		//free(buffer); //free le buffer lorsqu'il revient ici
		//buffer = NULL; // met le buffer a NULL si jamais le programme doit arrêter de manièere impromptue
	}
	va_end(va_list1);
	return (count);
}

int main()
{
	char c = 'C';

	ft_printf("%c\n", c);
	return (0);
}