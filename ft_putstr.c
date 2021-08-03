/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:52:39 by lhoerger          #+#    #+#             */
/*   Updated: 2021/08/03 16:10:52 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, col *col1)
{
	size_t	len;
	col1->minus = 0; //löschen dann
	if(!s)
	{
		ft_putstr("(null)", col1);
	}
	if (s)
	{
		len = ft_strlen(s);
		col1->len = col1->len + len;
		write(1, s, len);
	}
}
