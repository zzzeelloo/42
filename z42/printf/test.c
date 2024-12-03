#include <stdio.h>
#include <unistd.h>

// void	display_p(int x)
// {
// 	int *ptr;
// 	ptr = &x;

// 	printf("%p", &ptr);
// }

void	ft_putchar1(int c)
{
	write(1, &c , 1);
}
void	dec_to_hexa(int nbr)
{
	char tab_hexa[17] = "0123456789ABCDEF";
	char tab[32];
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (nbr > 0)
	{
		result = nbr % 16;
		tab[i] = tab_hexa[result];
		nbr = nbr / 16;
		i++;
	}
	while(i > 0)
	{
		i--;
		ft_putchar1(tab[i]);
	}
}
int main (void)
{
	int x = 255;
	dec_to_hexa(x);
	// printf("\n%p", &x);
}