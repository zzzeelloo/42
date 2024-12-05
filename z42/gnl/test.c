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

#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 5 // Permet de définir une taille modifiable pour le buffer

// Calcule la longueur d'une chaîne
int ft_strlen(char *str) {
    int i = 0;
    if (!str) // Ajout d'une vérification pour éviter les pointeurs NULL
        return 0;
    while (str[i])
        i++;
    return i;
}

// Cherche un caractère spécifique dans une chaîne et retourne un pointeur dessus
char *ft_strchr_mod(char *str) {
    if (!str) // Gestion du cas NULL
        return NULL;
    while (*str) {
        if (*str == '\n')
            return str;
        str++;
    }
    return NULL;
}

// Concatène deux chaînes, tout en allouant dynamiquement la mémoire nécessaire
char *ft_strjoin(char *str, char *str1) {
    int i = 0, y = 0;
    char *tab;

    if (!str && !str1) // Gestion des deux chaînes NULL
        return NULL;

    tab = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(str1) + 1));
    if (!tab)
        return NULL;

    if (str) { // Ajout pour éviter des erreurs si str est NULL
        while (str[i]) {
            tab[i] = str[i];
            i++;
        }
    }

    if (str1) { // Ajout pour éviter des erreurs si str1 est NULL
        while (str1[y]) {
            tab[i + y] = str1[y];
            y++;
        }
    }

    tab[i + y] = '\0';
    free(str); // Libération de l'ancienne chaîne pour éviter les fuites
    return tab;
}

// Vérifie si une chaîne contient un caractère '\n'
int check_end_line(char *str) {
    if (!str) // Gestion du cas NULL
        return 0;
    while (*str) {
        if (*str == '\n')
            return 1;
        str++;
    }
    return 0;
}

// Lit une ligne depuis un fichier
char *get_line(char *str, int fd) {
    char *read_buff;
    int r;

    read_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!read_buff)
        return NULL;

    while (!check_end_line(str)) { // Condition corrigée pour éviter une boucle infinie
        r = read(fd, read_buff, BUFFER_SIZE);
        if (r < 0) { // Gestion des erreurs de lecture
            free(read_buff);
            return NULL;
        }
        if (r == 0) // Fin de fichier
            break;
        read_buff[r] = '\0';
        str = ft_strjoin(str, read_buff); // Ajout de `str` dans la concaténation
        if (!str) { // Vérification après concaténation
            free(read_buff);
            return NULL;
        }
    }

    free(read_buff); // Libération de `read_buff` après utilisation
    return str;
}

// Extrait la ligne jusqu'au premier '\n'
char *get_the_line(char *line) {
    int i = 0;
    char *real_line;

    if (!line) // Gestion du cas NULL
        return NULL;

    while (line[i] && line[i] != '\n') // Correction de la condition de boucle
        i++;

    real_line = malloc(sizeof(char) * (i + 2)); // +2 pour inclure '\n' et '\0'
    if (!real_line)
        return NULL;

    i = 0;
    while (line[i] && line[i] != '\n') {
        real_line[i] = line[i];
        i++;
    }

    if (line[i] == '\n') { // Ajout du '\n' si présent
        real_line[i] = line[i];
        i++;
    }

    real_line[i] = '\0'; // Fin de la chaîne
    return real_line;
}

// Met à jour la "stash" pour contenir le reste après '\n'
char *update_stash(char *stash) {
    char *new_stash;
    char *newline_pos;
    int i = 0;

    newline_pos = ft_strchr_mod(stash);
    if (!newline_pos) { // Aucun '\n' trouvé, libérer et retourner NULL
        free(stash);
        return NULL;
    }

    new_stash = malloc(sizeof(char) * (ft_strlen(newline_pos + 1) + 1)); // +1 pour le '\0'
    if (!new_stash)
        return NULL;

    newline_pos++; // Passer après le '\n'
    while (newline_pos[i]) {
        new_stash[i] = newline_pos[i];
        i++;
    }

    new_stash[i] = '\0';
    free(stash); // Libération de l'ancienne stash
    return new_stash;
}

// Implémentation de `get_next_line`
char *get_next_line(int fd) {
    static char *stash;
    char *next_line;

    if (fd < 0 || BUFFER_SIZE <= 0) // Validation des paramètres
        return NULL;

    stash = get_line(stash, fd); // Lecture et ajout au stash
    if (!stash) // Vérification après lecture
        return NULL;

    next_line = get_the_line(stash); // Extraction de la ligne
    stash = update_stash(stash); // Mise à jour de la stash

    return next_line;
}

