/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:25:11 by osancak           #+#    #+#             */
/*   Updated: 2025/06/16 02:13:44 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flag(char c, va_list ap)
{
	int		steps;
	size_t	ptr;

	steps = 0;
	if (c == 'c')
		steps += ft_putchr(va_arg(ap, int));
	else if (c == 's')
		steps += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		steps += ft_putnbr(va_arg(ap, int), DECIMAL, 0);
	else if (c == 'u')
		steps += ft_putnbr(va_arg(ap, unsigned int), DECIMAL, 1);
	else if (c == 'x')
		steps += ft_putnbr(va_arg(ap, unsigned int), HEXA_DOWN, 1);
	else if (c == 'X')
		steps += ft_putnbr(va_arg(ap, unsigned int), HEXA_UP, 1);
	else if (c == 'p')
	{
		ptr = va_arg(ap, size_t);
		if (!ptr)
			steps += ft_putstr("(nil)");
		else
			steps += ft_putstr("0x") + ft_putnbr(ptr, HEXA_DOWN, 1);
	}
	return (steps);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		steps;

	steps = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			steps += ft_putchr(*format++);
		else if (*(format + 1) == '%' && format++ && format++)
			steps += ft_putchr('%');
		else
		{
			format++;
			steps += ft_flag(*format++, ap);
		}
	}
	va_end(ap);
	return (steps);
}
