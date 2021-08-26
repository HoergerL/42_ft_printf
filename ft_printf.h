#ifndef PRINTF_H
# define PRINTF_H

#include <stddef.h>
#include <unistd.h>
# include "./libft/libft.h"

typedef struct s_col 
{
	int minus;
	int zero;
	int precision;
	int width;
	int plus;
	int space;
	int hash;
	int len;

} col;

int ft_printf(const char * format, ...);

void	ft_putptr(void *ptr, col *col1);
void 	ft_puthex(unsigned long int i, col *col1, int is_capital);
void	ft_putunsigndec(unsigned int i, col *col1);
void	ft_putstr(char *s, col *col1);
void	ft_putchar_flags(char c, col *col1);
void	ft_putchar(char c);
void	ft_putnbr(int n, col *col1);

//utils
void	ft_print_col(col col1);
int	ft_lenHelper(int x);
void ft_fill_spaces(int x);
#endif