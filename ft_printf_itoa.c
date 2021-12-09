/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:31:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/09 15:51:02 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nb_length(unsigned long long n)
{
	int	length;

	length = 0;
	while (n >= 10)
	{
		n = n / 10;
		length++;
	}
	if (n >= 0 && n < 10)
		length++;
	return (length);
}

/*char	*ft_printf_itoa(unsigned long n, char **buf)
{
	int				size;
	int				i;
	//long long		nb;

	//nb = (long long)n;
	size = nb_length(n);
	*buf = (char *)malloc((size + 1) * sizeof(*buf));
	if (!*buf)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		*buf[i] = '-';
		n = -n;
	}
	i = size - 1;
	while (n >= 10)
	{
		*buf[i--] = (n % 10 + 48);
		n = n / 10;
	}
	*buf[i] = (char)(n % 10 + 48);
	*buf[size] = '\0';
	return (str);
}

char	*ft_printf_itoa1(size_t n, char **buf)
{
	int	size;
	int	i;

	size = nb_length(n);
	*buf = (char *)malloc((size + 1) * sizeof(*buf));
	if (!*buf)
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		*buf[i] = '-';
		nb = -nb;
	}
	i = size - 1;
	while (nb >= 10)
	{
		*buf[i--] = (nb % 10 + 48);
		nb = nb / 10;
	}
	*buf[i] = (char)(nb % 10 + 48);
	*buf[size] = '\0';
	return (*buf);
}*/