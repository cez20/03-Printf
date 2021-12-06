/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:39:49 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/06 14:15:01 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main (void)
{
	int a = 2147483647;
	int b = -2147483648;
	char c = '\0';	
	char d = '#';
	char *str = "Cesar Alejandro Menjivar";
	char *str1 = "";
	char *str2 = " ";
	char *str3 = "\0";

	printf ("\n*******************TEST (c)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %c\n", d);
	ft_printf("FT_PRINTF donne un resultat de ----> %c\n", d);
	printf   ("PRINTF number of characters is    ----> %d\n", printf   ("%d\n", d));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%d\n", d));
	printf ("******************************************************************\n\n");

	printf ("*******************TEST (s #1)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %s\n", str);
	ft_printf("FT_PRINTF donne un resultat de ----> %s\n", str);
	printf   ("PRINTF number of characters is    ----> %d\n", printf("%s\n", str));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%s\n", str));
	printf ("******************************************************************\n\n");

	printf ("*******************TEST (s #2)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %s\n", str1);
	ft_printf("FT_PRINTF donne un resultat de ----> %s\n", str1);
	printf   ("PRINTF number of characters is    ----> %d\n", printf("%s\n", str1));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%s\n", str1));
	printf ("******************************************************************\n\n");

	printf ("*******************TEST (s #3)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %s\n", str2);
	ft_printf("FT_PRINTF donne un resultat de ----> %s\n", str2);
	printf   ("PRINTF number of characters is    ----> %d\n", printf("%s\n", str2));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%s\n", str2));
	printf ("******************************************************************\n\n");

	printf ("*******************TEST (s #4)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %s\n", str3);
	ft_printf("FT_PRINTF donne un resultat de ----> %s\n", str3);
	printf   ("PRINTF number of characters is    ----> %d\n", printf("%s\n", str3));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%s\n", str3));
	printf ("******************************************************************\n\n");

	printf ("\n*******************TEST (p #1)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %p\n", &a);
	ft_printf("FT_PRINTF donne un resultat de ----> %p\n", &a);
	printf   ("PRINTF number of characters is    ----> %d\n", printf("%p\n", &a));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%p\n", &a));
	printf ("******************************************************************\n\n");

	printf ("\n*******************TEST (p #2)*******************************\n");
	printf   ("PRINTF donne un resultat de ---->    %p\n", (void *)-1);
	ft_printf("FT_PRINTF donne un resultat de ----> %p\n", (void *)-1);
	printf   ("PRINTF number of characters is    ----> %d\n", printf("%p\n", (void *)-1));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%p\n", (void *)-1));
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
	printf   ("PRINTF donne un resultat de ---->    %x\n", a);
	ft_printf("FT_PRINTF donne un resultat de ----> %x\n", a);
	printf   ("PRINTF number of characters is    ----> %d\n", printf("%x\n", a));
	ft_printf("FT_PRINTF number of characters is ----> %d\n", ft_printf("%x\n", a));
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
