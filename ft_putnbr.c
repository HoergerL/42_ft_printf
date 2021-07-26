/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:04:13 by lhoerger          #+#    #+#             */
/*   Updated: 2021/07/26 14:43:24 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"

void	ft_putnbr(int n)
{
	int	new_n;

	new_n = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", ft_strlen("-2147483648"));
		return ;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if (n / 10 == 0)
	{
		n = n + 48;
		write(1, &n, 1);
		return ;
	}
	new_n = n / 10;
	ft_putnbr(new_n);
	n = (n % 10) + 48;
	write(1, &n, 1);
}
