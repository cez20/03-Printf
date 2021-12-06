/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:39:49 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/02 13:21:21 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main (void)
{
	int a = 456297;
	int b = -14589;
	char c = 'Z';
	char *str = "Cesar Alejandro Menjivar";

	printf ("\n*******************TEST (c)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %c\n", c);
	ft_printf("FT_PRINTF donne un resultat de ----> %c\n", c);
	printf   ("PRINTF number of characters is    ----> %d\n", printf   ("%d\n", c));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%d\n", c));
	printf ("******************************************************************\n\n");

	printf ("*******************TEST (s)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %s\n", str);
	ft_printf("FT_PRINTF donne un resultat de ----> %s\n", str);
	printf   ("PRINTF number of characters is    ----> %d\n", printf("%s\n", str));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%s\n", str));
	printf ("******************************************************************\n\n");

	printf ("\n*******************TEST (p)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %p\n", &a);
	ft_printf("FT_PRINTF donne un resultat de ----> %p\n", &a);
	printf   ("PRINTF number of characters is    ----> %d\n", printf("%p\n", &a));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%p\n", &a));
	printf ("******************************************************************\n\n");

	printf ("\n*******************TEST (d)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %d\n", a);
	ft_printf("FT_PRINTF donne un resultat de ----> %d\n", a);
	printf   ("PRINTF number of characters is    ----> %d\n", printf("%d\n", a));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%d\n", a));
	printf ("******************************************************************\n\n");

	printf ("*******************TEST (i)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %i\n", b);
	ft_printf("FT_PRINTF donne un resultat de ----> %i\n", b);
	printf   ("PRINTF number of characters is    ----> %d\n", printf("%i\n", b));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%i\n", b));
	printf ("******************************************************************\n\n");

	printf ("*******************TEST (u)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %u\n", b);
	ft_printf("FT_PRINTF donne un resultat de ----> %u\n", b);
	printf   ("PRINTF number of characters is    ----> %d\n", printf("%u\n", b));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%u\n", b));
	printf ("******************************************************************\n\n");

	printf ("*******************TEST (x)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %x\n", b);
	ft_printf("FT_PRINTF donne un resultat de ----> %x\n", b);
	printf   ("PRINTF number of characters is    ----> %d\n", printf("%x\n", b));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%x\n", b));
	printf ("******************************************************************\n\n");

	printf ("*******************TEST (X)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %X\n", b);
	ft_printf("FT_PRINTF donne un resultat de ----> %X\n", b);
	printf   ("PRINTF number of characters is    ----> %d\n", printf("%x\n", b));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%x\n", b));
	printf ("******************************************************************\n\n");

	printf ("*******************TEST (PERCENT)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %%\n");
	ft_printf("FT_PRINTF donne un resultat de ----> %%\n");
	printf   ("PRINTF number of characters is    ----> %d\n", printf("%%\n"));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%%\n"));
	printf ("******************************************************************\n\n");

	printf ("*******************TEST (MIXED #1)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %c %s %p %d %i %u\n", c, str, str, a, b, a);
	ft_printf("FT_PRINTF donne un resultat de ----> %c %s %p %d %i %u\n", c, str, str, a, b, a);
	printf   ("PRINTF number of characters is    ----> %d\n", printf   ("%c %s %p %d %i %u\n", c, str, str, a, b, a));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%c %s %p %d %i %u\n", c, str, str, a, b, a));
	printf ("******************************************************************\n\n");

	printf ("*******************TEST (MIXED #2)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %d %c %i %u %p %s\n", a, c, b, b, str, str);
	ft_printf("FT_PRINTF donne un resultat de ----> %d %c %i %u %p %s\n", a, c, b, b, str, str);
	printf   ("PRINTF number of characters is    ----> %d\n", printf   ("PRINTF donne un resultat de ---->       %d %c %i %u %p %s\n", a, c, b, b, str, str));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("FT_PRINTF donne un resultat de ---->    %d %c %i %u %p %s\n", a, c, b, b, str, str));
	printf ("******************************************************************\n\n");
}