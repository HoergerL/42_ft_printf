/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:52:39 by lhoerger          #+#    #+#             */
/*   Updated: 2021/08/27 08:17:34 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_do_calculation(int n, int *len, int new_n)
{
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		*len = *len + 1;
	}
	if (n / 10 == 0)
	{
		n = n + 48;
		write(1, &n, 1);
		*len = *len + 1;
		return (0);
	}
	new_n = n / 10;
	ft_putnbr(new_n, len);
	n = (n % 10) + 48;
	write(1, &n, 1);
	*len = *len + 1;
	return (1);
}

void	ft_putnbr(int n, int *len)
{
	int	new_n;

	new_n = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", ft_strlen("-2147483648"));
		*len = *len + 11;
		return ;
	}
	if (!(ft_do_calculation(n, len, new_n)))
		return ;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s, int *length)
{
	size_t	len;

	if (!s)
		ft_putstr("(null)", length);
	if (s)
	{
		len = ft_strlen(s);
		length = length + len;
		write(1, s, len);
	}
}

void	ft_putptr(void *ptr, int *len)
{
	write (1, "0x", 2);
	*len = *len + 2;
	ft_puthex((unsigned long) ptr, len, 0);
}
