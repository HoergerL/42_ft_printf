/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:54:57 by lhoerger          #+#    #+#             */
/*   Updated: 2021/08/03 16:05:00 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// typedef struct s_col 
// {
// 	int minus;
// 	int zero;
// 	int precision;
// 	int width;
// 	int plus;
// 	int space;
// 	int hash;
// 	int len;

// } col;


size_t	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
	{
		cnt++;
	}
	return (cnt);
}

void ft_print_col(col col1)
{
	printf("\n\ncol:\n");
	printf("minus: %i\n", col1.minus);
	printf("zero: %i\n", col1.zero);
	printf("precision: %i\n", col1.precision);
	printf("width: %i\n", col1.width);
	printf("plus: %i\n", col1.plus);
	printf("space: %i\n", col1.space);
	printf("hash: %i\n", col1.hash);
	printf("len: %i\n\n\n", col1.len);
}

int	ft_lenHelper(int x)
{
	if (x >= 1000000000)
		return (10);
	if (x >= 100000000)
		return (9);
	if (x >= 10000000)
		return (8);
	if (x >= 1000000)
		return (7);
	if (x >= 100000)
		return (6);
	if (x >= 10000)
		return (5);
	if (x >= 1000)
		return (4);
	if (x >= 100)
		return (3);
	if (x >= 10)
		return (2);
	return (1);
}

void ft_fill_spaces(int x)
{
	while ((x) - 1 > 0)
		{
			// ft_putnbr(col1->width);
			// ft_putchar('\n');
			(x)--;
			ft_putchar(' ');
		}
}