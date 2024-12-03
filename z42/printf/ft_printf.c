
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>


int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		i = i + 6;
		return (i);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
int	ft_putchar1(int c)
{
	write(1, &c , 1);
	return (1);
}

int	dec_to_hexa(long long int nbr, char *base)
{
	char tab[32];
	int	result;
	int	i;
	int count;

	i = 0;
	result = 0;
	count = 0;
	if (nbr == 0)
	{
		ft_putchar1('0');
		count++;
	}
	if (nbr < 0)
		nbr = 4294967295 + nbr + 1;
	while (nbr > 0)
	{
		result = nbr % 16;
		tab[i] = base[result];
		nbr = nbr / 16;
		i++;
	}
	while(i > 0)
	{
		i--;
		count = count + ft_putchar1(tab[i]);
	}
	return (count);
}

int	put_pointer(void  *x, char * base)
{
	uintptr_t ptr;
	int count;
	char tab[32];
	int i;
	int result;

	i = 0;
	ptr = (uintptr_t)x;
	count = 0;
	if (!x)
		return(ft_putstr("(nil)"));
	write(1, "0x", 2);
	while (ptr > 0)
	{
		result = ptr % 16;
		tab[i] = base[result];
		ptr = ptr / 16;
		i++;
	}
	while(i > 0)
	{
		i--;
		count = count + ft_putchar1(tab[i]);
	}
	return (count + 2);
}
int	ft_putnbr_uns(long long int nbr)
{
	int	count;

	count = 1;
	if (nbr < 0)
		nbr = 4294967295 + nbr + 1;
	if (nbr >= 10)
	{
		count = count + ft_putnbr_uns(nbr / 10);
	}
	ft_putchar1(nbr % 10 + '0');
	return (count);

}
int	ft_putnbr(int nbr)
{
	int count;

	count = 1;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr  < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
		count++;
	}
	if (nbr >= 10)
	{
		count = count + ft_putnbr(nbr / 10);
	}
	ft_putchar1(nbr % 10 + '0');
	return (count);
}

int	ft_what_param(char *str, va_list args, int *i)
{
	int	count;

	count = 0;
	if (str[*i + 1] == 'c')
		count = count + ft_putchar1((char)va_arg(args, int));
	if (str[*i + 1] == 's')
		count = count + ft_putstr(va_arg(args, char *));
	if (str[*i + 1] == 'i')
		count = count + ft_putnbr(va_arg(args, int));
	if (str[*i + 1] == 'd')
		count = count + ft_putnbr(va_arg(args, int));
	if (str[*i + 1] == 'u')
		count = count + ft_putnbr_uns(va_arg(args, unsigned int));
	if (str[*i + 1] == 'x')
		count = count + dec_to_hexa(va_arg(args, int), "0123456789abcdef");
	if (str[*i + 1] == 'X')
		count = count + dec_to_hexa(va_arg(args, int), "0123456789ABCDEF");
	if (str[*i + 1] == '%')
		count = count + ft_putchar1('%');
	if (str[*i + 1] == 'p')
		count = count + put_pointer(va_arg(args,void *), "0123456789abcdef");
	return (count);
}

int ft_printf(const char * str, ...)
{
	int	count;
	va_list args;
	int	i;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
			count = count + ft_putchar1(str[i]);
		if (str[i] == '%')
		{
			count  = count + ft_what_param((char *)str, args, &i);
			i++;
		}
		i++;
	}
	va_end(args);
	//count = 0;
	return (count);
}
// int main(void)
// {
// 	ft_printf(" NULL %s NULL ", NULL);
// 	printf(" NULL %s NULL ", NULL);
// 	printf("\nvaleur de count : %d\n" ,ft_printf("%x", 0));
// 	printf("\n");
// 	printf("\nvaleur de count : %d",printf("%x", 0));
//}
