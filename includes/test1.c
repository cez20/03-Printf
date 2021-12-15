/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:48:07 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/11 17:04:29 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int  main()
{
    char *str = "Cesar";
    char **str1 = &str;
    int i;

    i = 0;
   
    *(str + i) = (char)'q';
   
    printf("%c\n", *str);
    printf("%c\n", str[0]);
    printf("%c\n", **str1);
    printf("%c\n", *str1[0]);
    printf("%c\n", *(*str1 + i));
    printf("%c\n", (**str1) + i);
    printf("%c\n", **(str1 + i));
    

    printf("%c\n", *(*str1 + i));
    printf("%c\n", (*str1)[i]);
}