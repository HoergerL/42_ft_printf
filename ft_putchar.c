/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:39:07 by lhoerger          #+#    #+#             */
/*   Updated: 2021/08/03 16:06:35 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_flags(char c, col *col1)
{
	
	//printf("erreicht putchar\n");
	// printf("\n\n colwidth ft_putchar_flag: %i" + col1->width);
	if (col1->width)
	{
		//printf("erreicht if in putchar\n");
		col1->len = col1->len + col1->width;
		if (col1->minus)
		{
				write(1, &c, 1);
				ft_fill_spaces(col1->width);
		}

		if (!(col1->minus))
		{
			ft_fill_spaces(col1->width);
			write(1, &c, 1);
		}
	}
	else
	{
		//printf("erreicht else in putchar\n");
		col1->len = col1->len + 1;
		write(1, &c, 1);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

