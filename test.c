/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:36:12 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/07 14:53:55 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*

Gérer toute combinaison des drapeaux suivants : ’-0.’ et la largeur minimale du
champ avec toutes les conversions.

Gérez tous les flags suivants : ’# +’ (oui espace est un flag valide)

 `-'        A negative field width flag; the converted value is to be left adjusted on the field boundary.
            Except for n conversions, the converted value is padded on the right with blanks, rather than on
            the left with blanks or zeros.  A - overrides a 0 if both are given.

`0' (zero)  Zero padding.  For all conversions except n, the converted value is padded on the left with zeros
            rather than blanks.  If a precision is given with a numeric conversion (d, i, o, u, i, x, and X),
            the 0 flag is ignored.

'.' (period) ; An optional precision, in the form of a period . followed by an optional digit string.  If the digit string is
         omitted, the precision is taken as zero.  This gives the minimum number of digits to appear for d, i, o, u, x,
         and X conversions, the number of digits to appear after the decimal-point for a, A, e, E, f, and F conversions,
         the maximum number of significant digits for g and G conversions, or the maximum number of characters to be
         printed from a string for s conversions.

`#'     The value should be converted to an ``alternate form''.  For c, d, i, n, p, s, and u conversions,
        this option has no effect.  For o conversions, the precision of the number is increased to force
        the first character of the output string to a zero.  For x and X conversions, a non-zero result
    	has the string `0x' (or `0X' for X conversions) prepended to it.  For a, A, e, E, f, F, g, and G
        conversions, the result will always contain a decimal point, even if no digits follow it (nor-
        mally, a decimal point appears in the results of those conversions only if a digit follows).  For
        g and G conversions, trailing zeros are not removed from the result as they would otherwise be.

` ' (space)  A blank should be left before a positive number produced by a signed conversion (a, A, d, e, E, f,
                      F, g, G, or i).

 `+'     A sign must always be placed before a number produced by a signed conversion.  A + overrides a
            space if both are used.

width:	An optional decimal digit string specifying a minimum field width.  If the converted value has fewer characters
         than the field width, it will be padded with spaces on the left (or right, if the left-adjustment flag has been
         given) to fill out the field width. 

*/

int main()
{
	char letter = 'C';
	char *str = "Cesar Menjivar";
	int number = -245689;
	int number1;

	// si on met un chiffre positif (ex: %24s) le texte se trouve à droite et le padding à gauche)
	// si on met un chiffre negatif (ex: %-24s) le texte se trouve àa GAUCHE et le PADDING à droite)
	// Idealement, on va prendre un buffer qui va prendre la longueur du chiffre, on remplira le champs par de espace et on mettra le texte avant de l'afficher. 
	// Ce n'est qu'en mettant un chiffre plus élévé que le strlen de que l'on affiche que l'effet du padding se ressentira. Si chiffre <= strlen(chiffre) = pas de padding visible.  

	printf("%d\n", printf("%2c", letter)); 
	printf("%d\n", printf("%-2c", letter)); 
	printf("%d\n", printf("%24s", str)); 
	printf("%d\n", printf("%-24s", str));  
	printf("%d\n", printf("%24p", &number)); 
	printf("%d\n", printf("%-24p", &number)); 
	printf("%d\n", printf("%24d", number)); 
	printf("%d\n", printf("%-24d", number)); 
	printf("%d\n", printf("%24i", number)); 
	printf("%d\n", printf("%-24i", number)); 
	printf("%d\n", printf("%24u", number)); 
	printf("%d\n", printf("%-24u", number)); 
	printf("%d\n", printf("%24x", number)); 
	printf("%d\n", printf("%-24x", number)); 
	printf("%d\n", printf("%24X", number)); 
	printf("%d\n", printf("%-24X", number)); 

	printf("Cesar%n Menj\n", &number1); // Est-ce qu'il y a une possibilité d'utiliser %n avec le '-' ? Probablement pas couvert
	printf("%d\n", number1); 
}