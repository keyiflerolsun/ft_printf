/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:36:29 by osancak           #+#    #+#             */
/*   Updated: 2025/06/16 00:11:25 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putnbr(long long number, char *base, int is_unsigned)
{
	int		res;
	int		rad;
	size_t	num;

	res = 0;
	rad = ft_strlen(base);
	if (is_unsigned)
		num = (size_t)number;
	else
		num = (unsigned long long)number;
	if (!is_unsigned && number < 0)
	{
		res += ft_putchr('-');
		num = -num;
	}
	if (num >= rad)
	{
		res += ft_putnbr(num / rad, base, is_unsigned);
		res += ft_putnbr(num % rad, base, is_unsigned);
	}
	else
		res += ft_putchr(base[num]);
	return (res);
}
