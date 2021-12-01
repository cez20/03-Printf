/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:56:00 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/01 15:42:19 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_new(unsigned int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd_new((n / 10), fd);
		n = n % 10;
	}
	if (n >= 0 && n < 10)
		ft_putchar_fd(n + '0', fd);
}

void	ft_putnbr_addr_hex(long long nbr, int *count)
{
	int			i;
	int			j;
	long long	remainder;
	char		hexadecimal[100];

	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	(*count) += 2;
	remainder = 0;
	j = 0;
	while (nbr != 0)
	{
		remainder = nbr % 16;
		if (remainder < 10)
			hexadecimal[j++] = 48 + remainder;
		else
			hexadecimal[j++] = ft_tolower(55 + remainder);
		nbr = nbr / 16;
		(*count)++;
	}
	i = j - 1;
	while (i >= 0)
		write (1, &hexadecimal[i--], 1);
}

void	ft_putnbr_int_hex(long long nbr, int *count)
{
	int			i;
	int			j;
	long long	remainder;
	char		hexadecimal[100];

	remainder = 0;
	j = 0;
	while (nbr != 0)
	{
		remainder = nbr % 16;
		if (remainder < 10)
			hexadecimal[j++] = 48 + remainder;
		else
			hexadecimal[j++] = ft_tolower(55 + remainder);
		nbr = nbr / 16;
		(*count)++;
	}
	i = j - 1;
	while (i >= 0)
		write (1, &hexadecimal[i--], 1);
}

void	ft_putnbr_int_hex1(long long nbr, int *count)
{
	int			i;
	int			j;
	long long	remainder;
	char		hexadecimal[100];

	remainder = 0;
	j = 0;
	while (nbr != 0)
	{
		remainder = nbr % 16;
		if (remainder < 10)
			hexadecimal[j++] = 48 + remainder;
		else
			hexadecimal[j++] = 55 + remainder;
		nbr = nbr / 16;
		(*count)++;
	}
	i = j - 1;
	while (i >= 0)
		write (1, &hexadecimal[i--], 1);
}

int	ft_printf(const char *str, ...)
{
	int				character_count;
	int				print_integer;
	int				character;
	unsigned int	number;
	long long		address;
	char			*print_string;
	va_list			va_list1;

	va_start(va_list1, str);
	character_count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
			{
				character = va_arg(va_list1, int);
				ft_putchar_fd(character, 1);
				str++;
				character_count++;
			}
			else if (*str == 's')
			{
				print_string = va_arg(va_list1, char *);
				ft_putstr_fd (print_string, 1);
				str++;
				character_count += ft_strlen(print_string);
			}
			else if (*str == 'p')
			{
				address = va_arg(va_list1, long long);
				ft_putnbr_addr_hex (address, &character_count);
				str++;
			}
			else if (*str == 'd' || *str == 'i')
			{
				print_integer = va_arg(va_list1, int);
				ft_putnbr_fd (print_integer, 1);
				ft_itoa_new(print_integer, &character_count);
				str++;
			}
			else if (*str == 'u')
			{
				number = va_arg(va_list1, unsigned int);
				ft_putnbr_fd_new (number, 1);
				ft_itoa_new1(number, &character_count);
				str++;
			}
			else if (*str == 'x')
			{
				address = va_arg(va_list1, long long);
				ft_putnbr_int_hex (address, &character_count);
				str++;
			}
			else if (*str == 'X')
			{
				address = va_arg(va_list1, long long);
				ft_putnbr_int_hex1(address, &character_count);
				str++;
			}
			else if (*str == '%')
			{
				ft_putchar_fd ('%', 1);
				str++;
				character_count++;
			}
			else 
			{
				ft_putchar_fd('%', 1);
				ft_putchar_fd(*str, 1);
				str++;
				character_count += 2;
			}
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			character_count++;
		}
	}
	va_end(va_list1);
	return (character_count);
}
