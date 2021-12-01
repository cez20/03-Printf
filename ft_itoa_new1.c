/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_new1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:11:35 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/01 15:15:00 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nb_length_new(unsigned int n)
{
	int	length;

	length = 0;
	if (n < 0)
	{
		n = -n;
		length++;
	}
	while (n >= 10)
	{
		n = n / 10;
		length++;
	}
	if (n >= 0 && n < 10)
		length++;
	return (length);
}

char	*ft_itoa_new1(unsigned int n, int *count)
{
	char			*str;
	int				size;
	int				i;
	
	size = nb_length_new(n);
	str = (char *)malloc((size + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	i = 0;
	i = size - 1;
	while (n >= 10)
	{
		str[i--] = (n % 10 + 48);
		n = n / 10;
	}
	str[i] = (char)(n % 10 + 48);
	str[size] = '\0';
	(*count) += ft_strlen(str);
	return (str);
}