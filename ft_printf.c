/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:13:05 by lhoerger          #+#    #+#             */
/*   Updated: 2021/07/12 20:18:08 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_putchar(char c);

void ft_putptr(void *ptr)
{
	write (1, "0x7ffc", 6);
	ft_puthex(ptr);
}

void ft_putunsigndec(unsigned int i) 
{
	if (i == 0)
		write(1, "0", 1);
	else if (i < 10)
	{
		i = i + '0';
		write(1, &i, 1);
	}
	else
	{
		ft_putunsigndec(i / 10);
		i = (i % 10) + '0';
		write(1, &i, 1);
	}
}

void ft_puthex(unsigned int i)
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
		ft_puthex(i / 16);
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

int ft_printf(const char * s, ...)
{
	va_list args;
	va_start(args, s);

	while (*s != '\0')
	{	
		//check, ob es nicht das Ende ist
		if (*s == '%')
		{
			if (s[1] == 'c')
				putchar(va_arg(args, int));
			else if (s[1] == 's')
				ft_putstr(va_arg(args, char *));
			else if (s[1] == 'p')
				ft_putptr(va_arg(args, void *));
			else if (s[1] == 'i' || s[1] == 'd')
				ft_putnbr(va_arg(args, int));
			else if (s[1] == 'u')
				ft_putunsigndec(va_arg(args, unsigned int));
			else if (s[1] == 'x')
				ft_puthex(va_arg(args, int));
			else if (s[1] == '%')
				ft_putchar('%');
			s++;
			//evtl else einbauen
		}
		else
			ft_putchar(s[0]);
		s++;
	}
	va_end(args);
}

int main()
{
	//printf("d: %d, %u", 123.23, 123.23)
	//printf("s:%");
	char c = '1';
	char *d = &c;
	printf("%x\n", 16);
	ft_puthex(16);
	//write(1, &d, 5);
	printf("%p", d);
	//ft_putunsigndec(34547545);
	//printf("%u", 34547545);
	ft_putstr("\n");
	ft_putptr(&c);
	ft_printf("\nhallotest, %s Laura\n", "Ich heiße");
}