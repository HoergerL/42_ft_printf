#ifndef PRINTF_H
# define PRINTF_H

#include <stddef.h>
#include <unistd.h>

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

void	ft_putptr(void *ptr);
void 	ft_puthex(unsigned long i);
void	ft_putunsigndec(unsigned int i);
void	ft_putstr(char *s);
void	ft_putchar(char c);

//utils
size_t	ft_strlen(const char *s);
void	ft_print_col(col col1);
int	ft_lenHelper(int x);
int	ft_isdigit(int c); //später entfernen
int	ft_atoi(const char *str); //später entfernen
#endif