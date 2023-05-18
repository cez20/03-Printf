/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 09:54:07 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/17 22:35:12 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf/ft_printf.h"

void	ft_putchar_new(char c, int *count, char **buf)
{
	*buf = malloc(1 * sizeof(char));
	if (!buf)
		return ;
	*(*buf) = c;
	write(1, *buf, 1);
	(*count)++;
}

void	ft_putstr_new(char *s, int *count, char **buf)
{
	if (!s)
	{
		*buf = malloc(7 * sizeof(char));
		ft_strlcpy (*buf, "(null)", 7);
	}
	else
		*buf = ft_strdup(s);
	write(1, *buf, ft_strlen(*buf));
	(*count) += ft_strlen(*buf);
}
