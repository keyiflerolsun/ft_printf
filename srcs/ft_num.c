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
	size_t	num;
	int		res;

	res = 0;
	if (!is_unsigned)
		num = (unsigned long long)number;
	else
		num = (size_t)number;
	if (!is_unsigned && number < 0)
	{
		res += ft_putchr('-');
		num = -num;
	}
	if (num >= ft_strlen(base))
	{
		res += ft_putnbr(num / ft_strlen(base), base, is_unsigned);
		res += ft_putnbr(num % ft_strlen(base), base, is_unsigned);
	}
	else
		res += ft_putchr(base[num]);
	return (res);
}

int	ft_pointer(size_t pointer)
{
	int	res;

	res = 0;
	if (!pointer)
		res += ft_putstr("(nil)");
	else
	{
		res += ft_putstr("0x");
		res += ft_putnbr(pointer, HEXA_DOWN, 1);
	}
	return (res);
}
