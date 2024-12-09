#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE		5
# endif

int     ft_strlen(char *str);
int 	check_end_line(char *str);
char    *ft_strchr_mod(char *str);
char    *ft_strjoin(char *str, char *str1);
char    *get_line(char *str, int fd);
char    *get_the_line(char *line);
char    *get_next_line(int fd);

#endif