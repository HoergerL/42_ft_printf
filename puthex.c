/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:44:09 by lhoerger          #+#    #+#             */
/*   Updated: 2021/07/27 21:11:01 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_puthex(unsigned long i, col *col1)
{
	//printf("Beginn: %i\n", i);
	if (i == 0)
		write(1, "0", 1);
	else if (i < 16)
	{
		if (i < 10)
		{
			i = i + '0';
			write(1, &i, 1);
		}
		else 
		{
			i = i + 'a' - 10;
			write(1, &i, 1);
		}
	}
	else
	{
		//printf("erreicht else\n");
		ft_puthex(i / 16, col1);
		if ((i % 16) < 10)
		{
			i = (i % 16) + '0';
			write(1, &i, 1);
		}
		else 
		{
			i = (i % 16) + 'a' - 10;
			write(1, &i, 1);
		}
	}
}
