/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:37:55 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/02 14:47:57 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h" 

int		ft_printf(const char *str, ...);
void	ft_putchar_new(char c, int *count);
void	ft_putnbr_new(int n, int *count);
void	ft_putnbr_new1(int n, int *count);
void	ft_putstr_new(char *s, int *count);
void	ft_putnbr_addr_hex(long long nbr, int *count);
void	ft_putnbr_hex_low(long long nbr, int *count);
void	ft_putnbr_hex_upp(long long nbr, int *count);

#endif