/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:56:00 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/11/19 12:16:47 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
/*

1- Qu'est-ce qu'un argument variadique? (va_start, va_end, va_cpy, va_arg)
2- Comment utiliser les kwargs en C? == Dictionary of keywords arguments. 

Règles communes:
1- Toute mémoire sur la heap doit être free
2- Si Makefile, doit contenir all, clean, fclean et re (Pas de PHONY)
3 - Si le projet autorise votre libft, vous devez copier ses sources et son Makefile
associé dans un dossier libft contenu à la racine. Le Makefile de votre projet doit
compiler la librairie à l’aide de son Makefile, puis compiler le projet. (IMPORTANT)
4 - La libft et les MAkefile sont autorisés

Partie obligatoire
1- Je dois recoder la fonction printf de la libc.
2- On NE doit PAS gérer de buffer contraire au vrai printf.
3- Vous devez gérer les conversions suivantes : cspdiuxX%
4- Vous devez utiliser la commande ar pour créer votre librairie, l’utilisation de la
commande libtool est interdite

Une petite description des conversions requises :
•%c imprime un seul caractère.
•%s imprime une chaîne de caractères.
•%p L’argument de pointeur void * est imprimé en hexadécimal.
•%d imprime un nombre décimal (base 10).
•%i imprime un entier en base 10.
•%u imprime un nombre décimal non signé (base 10).
•%x imprime un nombre en hexadécimal (base 16).
•%% imprime un signe de pourcentage..
*/

int ft_printf(const char *, ...); // in prototype there is no need to precise name of variable. Simply precise the type fo variable that they are waiting for. 

int ft_printf(const char *str, ...) 
{
	int		CharacterCount;
	int		PrintInteger; // variable that will contain integer to be printed %d. What to do with %i?
	char	character;  //Variable that prints character (%c)
	char	IntegerString[10]; // will contain integer. Size 10 because max integer is 2147483648 which contains 10 digits. 
	char	*pPrintString; // will print string that needs to be used. 
	//char	*PPrintAddress; // allows us to print memory address of %p. 
	va_list	VaList;

	va_start(VaList, str); // permet de savoir ou commencer avec les arguments non-connu

	CharacterCount = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
			{
				character = va_arg(VaList, int);
				ft_putchar_fd(character, 1);
				str++;
				CharacterCount++;
				break;  
			}
			else if (*str == 's')
			{
				pPrintString = va_arg(VaList, char *);
				ft_putstr_fd (pPrintString, 1);  //fputs(pPrintString, stdout); // Remplacer fputs par qqchose d'autres, sûrement write ft_putstr_fd
				str++; //Avance de 1 dans 
				CharacterCount += ft_strlen(pPrintString);
				break;
			}
			/*else if (*str = 'p') //To be completed
			{
				pPrintAddress = va_arg(VaList, void *)
				ft_isalnum // créer une fonction qui applique le ft_isalnum en loop
				************* 
				*************
			}*/
			else if (*str == 'd') // à valider
			{
				PrintInteger = va_arg (VaList, int);
				ft_itoa (PrintInteger); // or _itoa(PrintInteger, IntegerString, 10);
				ft_putstr_fd (IntegerString, 1);//fputs(IntegerString, stdout);
				str++;
				CharacterCount += ft_strlen(IntegerString);
				break;
			}
			else if (*str == 'i')
			{
				PrintInteger = va_arg (VaList, int);
				ft_itoa (PrintInteger); // or _itoa(PrintInteger, IntegerString, 10);
				ft_putstr_fd(IntegerString, 1); // le chiffre équivaut ici à stdout 0 = stdin 1 =stdout 2= stderr; 
				str++;
				CharacterCount += ft_strlen(IntegerString);
				break;
			}
			//else if (*str = 'u')
			//else if (*str = 'x')
			//else if (*str = 'X')
			else if (*str == '%') // À valider si même chose que le dernier "else"; 
			{
				ft_putchar_fd('%', 1);
				str++;
				CharacterCount++;
				break;
			}
			else
				ft_putchar_fd('%', 1);
				ft_putchar_fd(*str, 1);
				str++;
				CharacterCount += 2;
				break;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			CharacterCount++;
			break;
		}
	}
	va_end(VaList);
	return (CharacterCount); // What do I need the characterCount for ? While CharacterCount is 
}

int main ()
{
	int a = 42;
	int i = 0;
	char *str = "J'ai faim";

	printf("Mon nom est César et %s et j'ai aussi %d ans \n", str, a);
	
	while (i < 100)
	{
		ft_printf("Mon nom est César et %s et j'ai aussi %d ans\n");
		i++;
	}
	
}