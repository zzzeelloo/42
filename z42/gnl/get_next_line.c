#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

// void ft_putstr(char *str)
// {
// 	size_t i;

// 	i = 0;
// 	while(str)
// 	{
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// }

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
char	*ft_strchr_mod(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
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
char *get_line(char *str, int fd)
{
	char *read_buff;
	int r;

	read_buff = malloc(sizeof(char) * 5 + 1);//buffer_size a la place de 5
	if (!read_buff)
		return (NULL);
	while (1 || r == 0)
	{
		r = read(fd, read_buff, 5);//buffer_size a la place de 5
		read_buff[r] = '\0';
		str = ft_strjoin(str, read_buff);
		if (!str)
			return (NULL);
		if (check_end_line(str) == 1)
			break;
	}
	free(read_buff);
	return (str);
}
char *get_the_line(char *line)
{
	int i;
	char *real_line;

	i = 0;
	while (line[i] || line[i] == '\n')
		i++;
	real_line = malloc(sizeof(char) * (i + 1));
	if (!real_line)
		return (NULL);
	i = 0;
	while (line[i] || line[i] == '\n')
	{
		real_line[i] = line[i];
		i++;
	}
	// real_line[i] = '\n';
	real_line[i] = '\0';
	return (real_line);
}
char *get_next_line(int fd)
{
	// char *tab;
	char *next_line;
	static char *stash;

	stash = get_line(stash, fd);
	next_line = get_the_line(stash);
	stash = ft_strchr_mod(stash);
	free(stash);
	return(next_line);
}

int main(void) {
    int fd;
    char *line;

    // Ouvrir le fichier en lecture seule
    fd = open("fable.txt", O_RDONLY);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    // Lire et afficher chaque ligne du fichier
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
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
