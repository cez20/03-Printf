/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:27:42 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/18 00:20:11 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	total;
	size_t	initial;

	initial = size;
	total = ft_strlen(dst) + ft_strlen(src);
	while (*dst != 0 && size > 0)
	{
		dst++;
		size--;
	}
	if (size == 0)
		return (ft_strlen(src) + initial);
	while (*src != 0 && size > 1)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = 0;
	return (total);
}
