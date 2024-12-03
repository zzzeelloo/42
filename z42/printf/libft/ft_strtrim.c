/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:30:57 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/19 11:12:16 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	is_set(char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_set_start(char *str, char *set)
{
	int	i;
	int	n_set;

	i = 0;
	n_set = 0;
	while (str[i] && is_set(set, str[i]) == 1)
	{
		n_set++;
		i++;
	}
	return (n_set);
}

int	count_set_end(char *str, char *set)
{
	int	i;
	int	n_set;

	i = ft_strlen(str);
	n_set = 0;
	while (i > 0 && is_set(set, str[i - 1]) == 1)
	{
		n_set++;
		i--;
	}
	return (n_set);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	y;
	int		c_set;
	int		size_str;
	char	*str;

	i = count_set_start((char *)s1, (char *)set);
	y = 0;
	c_set = i + count_set_end((char *)s1, (char *)set);
	if (i >= ft_strlen(s1))
		size_str = 0;
	else
		size_str = ft_strlen((char *)s1) - c_set;
	str = malloc((size_str + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while ((size_t)size_str > y)
	{
		str[y] = s1[i];
		y++;
		i++;
	}
	str[y] = '\0';
	return (str);
}
// int main() 
// {
//     char *s1 = "./;Hello./;";
//     char *set = "./;";
//     char *trimmed = ft_strtrim(s1, set);
//     printf("Avant trim: '%s'\n", s1);
//     printf("Après trim: '%s'\n", trimmed);	
// }
// while (is_set(s1[start], s2) && s1)
// start ++;