#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>


int	ft_putstr(const char *str);
int	ft_putchar1(int c);
int	dec_to_hexa(int nbr, char *base);
int	ft_putnbr(int nbr);
int	put_pointer(void  *x, char * base);
int	ft_what_param(char *str, va_list args, int *i);
int ft_printf(const char * str, ...);

#endif