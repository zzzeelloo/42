#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_end_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char    *ft_strchr_mod(char *str)
{
    int		i;
    int		y;
    char *tab;

    i = 0;
    y = 0;
    while (str[i] != '\n') // compte ce qu'il y a avant \n
    {
        if (str[i] == '\0')
            return (NULL);
        i++;
    }
    if (str[i] == '\n' && str[i + 1] == '\0')
        return (NULL);
    tab = malloc(sizeof(char) * ((ft_strlen(str) + i) + 1)); // pour le soustraire ici
    if (!tab)
        return (NULL);
   i++; 
    while (i < ft_strlen(str))
    {
        tab[y] = str[i];
        y++;
        i++;
    }
    tab[y] = '\0';
    return (tab);
}

char *ft_strjoin(char *str, char *str1)
{
	int i;
	int y;
	char *tab;

	i = 0;
	y = 0;
	tab = malloc(sizeof(char) * (ft_strlen(str)+ ft_strlen(str1)) + 1);
	if (!tab)
		return (NULL);
	while (str[i] && (i < ft_strlen(str)))
	{
		tab[i] = str[i];
		i++;
	}
	while (str1[y] && ((i + y) < (ft_strlen(str1) + ft_strlen(str))))
	{
		tab[i + y] = str1[y];
		y++;
	}
	tab[i + y] = '\0';
	if (str)
		free(str);
	return(tab);
}