/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:33:12 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/03 16:43:11 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_new(char *s, int *count)
{
	if (!s)
	{
		write(1, "(null)", 6);
		(*count) += 6;
	}
	else
	{
		write(1, s, ft_strlen(s));
		(*count) += ft_strlen(s);
	}
}
