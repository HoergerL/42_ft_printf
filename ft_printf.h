/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:55:53 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 13:55:53 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

// ft_printf.c
// prints hexadecimal digit i
void	put_hexnbr(unsigned long int i, int is_capital);
//converts i to a hexadecimal number
void	ft_puthex(unsigned long int i, int *len, int is_capital);
// converts i to an unsigned int and prints it
void	ft_putunsigndec(unsigned int i, int *len);
// interprets the conversion and calls the fitting function
void	ft_find_conversion(char s, int *len, va_list args);
// recreation of printf
int		ft_printf(const char *format, ...);

//ft_printf_utils.c
// converts and prints an integer
int		ft_do_calculation(int n, int *len, int new_n);
//catches the edgecases of ft_do_calculation and calls it
void	ft_putnbr(int n, int *len);
// prints a char
void	ft_putchar(char c);
// prints a string
void	ft_putstr(char *s, int *lenght);
// prints a pointer
void	ft_putptr(void *ptr, int *len);

#endif