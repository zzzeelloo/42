/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:29:22 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/19 14:09:54 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>

int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *big, const char *little, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t count);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *pointer, int value, size_t count);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t count);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
void	*ft_calloc(size_t num, size_t size);
void	ft_bzero(void *pointer, size_t count);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char *str, char sep);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strdup(char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif