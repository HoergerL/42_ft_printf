/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:13:05 by lhoerger          #+#    #+#             */
/*   Updated: 2021/08/01 16:08:03 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

void ft_find_conversion(char s, col *col1, va_list args)
{
	//printf("kommt hier an mit buchstabe: %c", s);
	if (s == 'c')
		ft_putchar_flags(va_arg(args, int), col1);
	else if (s == 's')
		ft_putstr(va_arg(args, char *), col1);
	else if (s == 'p')
		ft_putptr(va_arg(args, void *), col1);
	else if (s == 'i' || s == 'd')
		ft_putnbr(va_arg(args, int), col1);
	else if (s == 'u')
		ft_putunsigndec(va_arg(args, unsigned int), col1);
	else if (s == 'x')
		ft_puthex(va_arg(args, int), col1);
	else if (s == '%')
		ft_putchar('%');
}

// - linksbündig, statt rechtsbündig (wichtig im Zusammenhang mit width)
// width = Zahl vor precision
// 0 +dahinter eine Zahl -> füllt auf so viele Stellen auf, wenn + dabei ist, dann nimmt es auch eine Stelle ein, für d, i, u, x
// . ("precision") macht das gleiche wie 0, aber 0 beachtet Zeichen (also auch +), während . nur Zahlen beachtet, gilt für i,d, x, u , precison 0 = nichts wird ausgegeben, wenn der Wert 0 ist, für s ist es die maximale Anzahl an zu druckenden charactern, wenn kein Wert für die Precision angegeben wird, dann ist sie 0, wenn Precision nicht angeben wird, ist sie 1
// .* -> die Precision ist im String nicht specified, sondern wird auch übergeben
// # hängt vor Hexadezimal also %#x immer ein 0x
//  setzt ein Leerzeichen vor die Zahl, die wir schreiben, aber nur vor positive
// + garantiert, dass Zahlen ein Vorzeichen haben -> +150 -> kommt direkt nach %-Zeichen


// + overrides space
// - overrides 0

void ft_reset_col(col *col1)
{
	col1->minus = 0;
	col1->zero = 0;
	col1->precision = 0;
	col1->width = 0;
	col1->plus = 0;
	col1->space = 0;
	col1->hash = 0;
}


int ft_printf(const char * format, ...)
{
	va_list args;
	int flags;
	va_start(args, format);
	col col1;

	
	col1.len = 0;
	while (*format != '\0')
	{	
		//printf("\nformat: %s\n", format);
		//printf("\n\nChar: %c\n", *format);
		//check, ob es nicht das Ende ist
		if (*format == '%')
		{
			format++;
			ft_reset_col(&col1);
			flags = 1;
			while (flags)
			{
				flags = 0;
				// if (*format == '%')
				// 	putchar('%');
				if (*format == '0')
				{
					//printf("#################NULL found, %s", format);
					col1.zero = 1;
					flags = 1;
				}
				else if (*format == '-')
				{
					col1.minus = 1;
					flags = 1;
				}
				else if (*format == '.')
				{
					col1.precision = ft_atoi(format + 1);
					format += ft_lenHelper(col1.precision);
					flags = 1;
					//printf("in precision: precision: %i, lenhelper: %i format: %s", col1.precision, ft_lenHelper(col1.precision), format);
				}
				else if (*format == '#')
				{
					col1.hash = 1;
					flags = 1;
				}
				else if (*format == '+')
				{
					col1.plus = 1;
					flags = 1;
				}
				else if (*format == '+')
				{
					col1.plus = 1;
					flags = 1;
				}
				else if (ft_isdigit(*format))
				{
					//printf("########################found width format: %s\n", format);
					flags = 1;
					col1.width = ft_atoi(format);
					format += ft_lenHelper(col1.width) - 1;
					//printf("in width: widht: %i, lenhelper: %i format: %s", col1.width, ft_lenHelper(col1.width), format);
				}
				if (flags == 1)
					format++;
			}
			//printf("Format:%s", format);
			//ft_print_col(col1);
			ft_find_conversion(*format, &col1, args);
			format++;
			//ft_print_col(col1);
		}
		
		else
		{
			ft_putchar(*format);
			format++;
			col1.len += 1;
		}
	}
	va_end(args);
	return (col1.len);
}


int main()
{
	//char c = '1';
	//char *d = &c;
	printf("|%10c|\n", 'a');
	ft_printf("|%10c|", 'a');
	//ft_printf( "%-#010s%-1d%#10.1c\n\n", "hello", 7, 'a' );
	//ft_printf( "%-0#10.4s%-10d%-10c\n", "hello", 7, 'a');
	//ft_printf("Test #: %#x\n\n", 17);
	// printf("%x\n", 16);
	// ft_puthex(16);
	// //write(1, &d, 5);
	// printf("%p", d);
	// //ft_putunsigndec(34547545);
	// //printf("%u", 34547545);
	// ft_putstr("\n");
	// ft_putptr(&c);
	 //ft_printf("\nhallotest, %s Laura\n", "Ich heiße");
}

// int main()
// {
// 	//printf("d: %d, %u", 123.23, 123.23)
// 	//printf("s:%");
// 	char c = '1';
// 	char *d = &c;
// 	printf( "%10s%10d%10c\n\n", "hello", 7, 'a' );
// 	printf( "%-10s%-10d%-10c\n", "hello", 7, 'a');
// 	//printf("Test #: %#x\n\n", 17);
// 	printf("%x\n", 16);
// 	ft_puthex(16);
// 	//write(1, &d, 5);
// 	printf("%p", d);
// 	//ft_putunsigndec(34547545);
// 	//printf("%u", 34547545);
// 	ft_putstr("\n");
// 	ft_putptr(&c);
// 	ft_printf("\nhallotest, %s Laura\n", "Ich heiße");
// // }
// int ft_printf(const char * s, ...)
// {
// 	va_list args;
// 	va_start(args, s);

// 	while (*s != '\0')
// 	{	
// 		//check, ob es nicht das Ende ist
// 		if (*s == '%')
// 		{
// 			if (s[1] == 'c')
// 				putchar(va_arg(args, int));
// 			else if (s[1] == 's')
// 				ft_putstr(va_arg(args, char *));
// 			else if (s[1] == 'p')
// 				ft_putptr(va_arg(args, void *));
// 			else if (s[1] == 'i' || s[1] == 'd')
// 				ft_putnbr(va_arg(args, int));
// 			else if (s[1] == 'u')
// 				ft_putunsigndec(va_arg(args, unsigned int));
// 			else if (s[1] == 'x')
// 				ft_puthex(va_arg(args, int));
// 			else if (s[1] == '%')
// 				ft_putchar('%');
// 			s++;
// 			//evtl else einbauen
// 		}
// 		else
// 			ft_putchar(s[0]);
// 		s++;
// 	}
// 	va_end(args);
// }