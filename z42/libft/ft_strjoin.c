/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:38:10 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/18 19:38:55 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size_str;
	int		i;
	int		y;

	str = 0;
	i = 0;
	y = 0;
	size_str = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * size_str + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		str[i + y] = s2[y];
		y++;
	}
	str[i + y] = '\0';
	return (str);
}
// int main()
// {
//     char *s1 = "Hello, ";
//     char *s2 = "world!";

//     char *result = ft_strjoin(s1, s2);
// 	printf("%s", result);
// }
