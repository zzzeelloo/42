#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int ft_strlen(char *str)
{
	size_t i = 0;

	while (str[i])
		i++;
	return (i);
}
char *ft_strjoin(char *str, char *str1)
{
	int i;
	int y;
	char *tab;

	i = 0;
	y = 0;
	tab = malloc(sizeof(char) * (ft_strlen(str1)+ ft_strlen(str1)) + 1);
	if (!tab)
	return (NULL);
	while (str[i])
	{
		tab[i] = str[i];
		i++;
	}
	while (str1[y])
	{
		tab[i + y] = str1[y];
		y++;
	}
	tab[i + y] = '\0';
	return(tab);
}
int main(void)
{
	char *tab;
	char *str = "oeoe le boss";
	char *str1 = " lacoste tn ou quoi";
	tab = ft_strjoin(str, str1);
	int z =ft_strlen(tab);
	printf("%s", tab);
}
