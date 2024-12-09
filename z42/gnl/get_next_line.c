#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE		5


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
    int    i;
    int y;
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

char *get_line(char *str, int fd)
{
	char *read_buff;
	int r;

	read_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// if (!read_buff)
	// 	return (NULL);
	while (1)
	{
		r = read(fd, read_buff, BUFFER_SIZE);
		if (r == 0)//fichier txt fini
			break ;
		if (r == -1) //si erreur de read
		{
			free(str);
            free(read_buff);
            return NULL;
        }
		read_buff[r] = '\0';
		str = ft_strjoin(str, read_buff);
		if (check_end_line(str) == 1) //arrive au \n
			break;
	}
	free(read_buff);
	return (str);
}
char *get_the_line(char *line)
{
	int i;
	char *real_line;

	if (!line)
		return(NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	real_line = malloc(sizeof(char) * (i + 2));// \n et \0
	if (!real_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		real_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		real_line[i] = '\n';
		i++;
	}
	real_line[i] = '\0';
	return (real_line);
}
char *get_next_line(int fd)
{
	static char *stash;
	char *next_line;
	char *odd_stash;

	if (fd == -1)
		return (NULL);
	stash = get_line(stash, fd);
	odd_stash = stash;
	next_line = get_the_line(stash);
	if (!next_line)
		return(NULL);
	stash = ft_strchr_mod(stash);
	free(odd_stash);
	return(next_line);
}

int main(void) {
    int fd;
    char *line;

    // Ouvrir le fichier en lecture seule
    fd = open("al-Ahzab.txt", O_RDONLY);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    // Lire et afficher chaque ligne du fichier
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        // Libérer la mémoire allouée par get_next_line (si nécessaire)
        free(line);
    }

    // Fermer le fichier
    close(fd);
    return 0;
}

// char *find_next_line(char *tab, int fd)
// {
// 	char *line;
// 	char *tab;
// 	int i = ft_strlen(stash);
// 	int y = 0;
	
// 	read (fd, tab, 5);
// 	// stash = malloc(sizeof(char) * 30);
// 	// stash = NULL;
// 	while (tab[i])
// 	{
// 		stash[i] = tab[y];
// 		i++;
// 		y++; 
// 	}
// 	y = 0;
// 	if (check_end_line(stash) == 1)
// 	{
// 		line = malloc(sizeof(char) * 30);
// 		while (stash[y] || stash[y] == '\n')
// 		{
// 			line[y] = stash[y];
// 			y++;
// 		}
// 		stash[i] = '\0';
// 		stash = ft_strchr(stash) + 1;
// 		return (line);
// 	}
// 	return(NULL);
// }
