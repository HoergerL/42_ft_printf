/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:52:39 by lhoerger          #+#    #+#             */
/*   Updated: 2021/07/27 21:08:22 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, col *col1)
{
	size_t	len;

	if (s)
	{
		len = ft_strlen(s);
		write(1, s, len);
	}
}
