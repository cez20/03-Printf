/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:56:00 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/11/30 16:18:30 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define LOWER_HEX "0123456789abcdef"
#define UPPER_HEX "0123456789ABCDEF"

void 	ft_putnbr_base(unsigned int nbr, int *num)
{
	int i;
	int j;
	int remainder;
	char hexadecimal[100];

	printf("%u\n", nbr);
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
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
		num++;	
	}
	i = j;
	while (i >= 0)
		write(1, &hexadecimal[i--], 1);
}

int	ft_printf(const char *str, ...)
{
	int				character_count;
	int				print_integer;
	unsigned int	address;
	int				character;
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
				address = va_arg(va_list1, int);
				ft_putnbr_base (address, &character_count);
				str++;
			}
			else if (*str == 'd' || *str == 'i')
			{
				print_integer = va_arg(va_list1, int);
				ft_putnbr_fd (print_integer, 1);
				str++;
				character_count++;
			}
			else
			{
				ft_putchar_fd ('%', 1);
				ft_putchar_fd (*str, 1);
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

int main (void)
{
	int a = 456297;
	int b = 268999;
	char c = 'Z';
	char *str = "Cesar Menjivar";

	printf ("\n*******************TEST CHAR (c)*******************************\n");
	printf("PRINTF donne un resultat de ----> %c\n", c);
	ft_printf("FT_PRINTF donne un resultat de ----> %c\n", c);
	printf ("******************************************************************\n\n");

	printf ("*******************TEST STRING (s)*******************************\n");
	printf("PRINTF donne un resultat de ----> %s\n", str);
	ft_printf("FT_PRINTF donne un resultat de ----> %s\n", str);
	printf ("******************************************************************\n\n");

	printf ("\n*******************TEST INTEGER (p)*******************************\n");
	printf("PRINTF donne un resultat de ----> %p\n", &a);
	ft_printf("FT_PRINTF donne un resultat de ----> %p\n", &a);
	printf ("******************************************************************\n\n");

	//les addresse commence par 0x, mais pas totue necessarirement par 0x10! 

	printf ("\n*******************TEST INTEGER (d)*******************************\n");
	printf("PRINTF donne un resultat de ----> %d\n", a);
	ft_printf("FT_PRINTF donne un resultat de ----> %d\n", a);
	printf ("******************************************************************\n\n");

	printf ("*******************TEST INTEGER (i)*******************************\n");
	printf("PRINTF donne un resultat de ----> %i\n", b);
	ft_printf("FT_PRINTF donne un resultat de ----> %i\n", b);
	printf ("******************************************************************\n\n");

}
