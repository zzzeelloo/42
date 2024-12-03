/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:31:24 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/19 14:00:40 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	is_a_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

int	c_word(char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_a_sep(str[i], sep))
			i++;
		if (str[i] && !is_a_sep(str[i], sep))
		{
			count++;
			while (str[i] && !is_a_sep(str[i], sep))
				i++;
		}
	}
	return (count);
}

int	add_word(char *str, int *i, char sep, char **str_result)
{
	int	start;
	int	len;

	start = *i;
	len = 0;
	while (str[*i] && !is_a_sep(str[*i], sep))
	{
		(*i)++;
		len++;
	}
	*str_result = ft_substr(str, start, len);
	return (*str_result != NULL);
}

char	**ft_split(char *str, char sep)
{
	int		i;
	int		j;
	char	**str_result;

	i = 0;
	j = 0;
	str_result = malloc(sizeof(char *) * (c_word(str, sep) + 1));
	if (!str_result)
		return (NULL);
	while (str[i])
	{
		while (str[i] && is_a_sep(str[i], sep))
			i++;
		if (str[i] && !add_word(str, &i, sep, &str_result[j++]))
		{
			while (j > 0)
				free(str_result[--j]);
			free(str_result);
			return (NULL);
		}
	}
	str_result[j] = NULL;
	return (str_result);
}
// int main(void)
// {
// 	int z = 0;
// 	int y =	c_word("Je/veux/le/monde", '/');
// 	char **str_f = 0;

// 	str_f = ft_split("Je/veux/le/monde", '/');
// 	while(z <= y)
// 	{
// 		printf("\n%d", z);
// 		printf("%s", str_f[z]);

// 		z++;
// 	}
// }