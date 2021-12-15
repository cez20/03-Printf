/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:01:29 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/12/15 18:50:11 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h" 
# define LOW_HEX "0123456789abcdef"
# define UP_HEX  "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
void	ft_putchar_new(char c, int *count, char **buf);
void	ft_putstr_new(char *s, int *count, char **buf);
void	ft_putnbr_new(size_t n, int *count, char **buf);
void	ft_putnbr_new1(int n, int *count, char **buf);
int		nb_length(long long n);
int		nb_length1(unsigned int n);
void	ft_putnbr_hex(size_t num, char *base, int *count, char **buf);
void	ft_putnbr_hex1(size_t num, char *base, int *count, char **buf);
void	ft_putnbr_recurs(size_t num, char *base, char **buf, int *i);
size_t	hex_size(size_t nb);

#endif