/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:39:07 by lhoerger          #+#    #+#             */
/*   Updated: 2021/07/27 21:41:26 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_flags(char c, col *col1)
{
	// printf("\n\n colwidth ft_putchar_flag: %i" + col1->width);
	if (col1->width)
	{
		if (col1->minus)
				write(1, &c, 1);
		while ((col1->width) - 1 > 0)
		{
			// ft_putnbr(col1->width);
			// ft_putchar('\n');
			(col1->width)--;
			ft_putchar(' ');
		}
		if (!(col1->minus))
			write(1, &c, 1);
	}
	else
	{
		write(1, &c, 1);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

