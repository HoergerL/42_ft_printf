/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:13:05 by lhoerger          #+#    #+#             */
/*   Updated: 2021/08/27 09:58:01 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

void	put_hexnbr(unsigned long int i, int is_capital)
{
	if ((i % 16) < 10)
	{
		i = (i % 16) + '0';
		write(1, &i, 1);
	}
	else if (is_capital)
	{
		i = (i % 16) + 'A' - 10;
		write(1, &i, 1);
	}
	else
	{
		i = (i % 16) + 'a' - 10;
		write(1, &i, 1);
	}
}

void	ft_puthex(unsigned long int i, int *len, int is_capital)
{
	if (i == 0)
	{
		*len = *len + 1;
		write(1, "0", 1);
	}
	else if (i < 16)
	{
		*len = *len + 1;
		put_hexnbr(i, is_capital);
	}
	else
	{
		*len = *len + 1;
		ft_puthex(i / 16, len, is_capital);
		put_hexnbr(i, is_capital);
	}
}

void	ft_putunsigndec(unsigned int i, int *len)
{
	if (i == 0)
	{
		write(1, "0", 1);
		*len = *len + 1;
	}
	else if (i < 10)
	{
		i = i + '0';
		write(1, &i, 1);
		*len = *len + 1;
	}
	else
	{
		ft_putunsigndec(i / 10, len);
		i = (i % 10) + '0';
		write(1, &i, 1);
		*len = *len + 1;
	}
}

void	ft_find_conversion(char s, int *len, va_list args)
{
	if (s == 'c')
		ft_putchar(va_arg(args, int));
	else if (s == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (s == 'p')
		ft_putptr(va_arg(args, void *), len);
	else if (s == 'i' || s == 'd')
		ft_putnbr(va_arg(args, int), len);
	else if (s == 'u')
		ft_putunsigndec(va_arg(args, unsigned int), len);
	else if (s == 'x')
		ft_puthex((unsigned long int) va_arg(args, unsigned int), len, 0);
	else if (s == 'X')
		ft_puthex(va_arg(args, unsigned int), len, 1);
	else if (s == '%')
	{
		ft_putchar('%');
		len = len + 1;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = 0;
	while (*format != '\0')
	{	
		if (*format == '%')
		{
			format++;
			ft_find_conversion(*format, &len, args);
			format++;
		}
		else
		{
			ft_putchar(*format);
			format++;
			len += 1;
		}
	}
	va_end(args);
	return (len);
}
