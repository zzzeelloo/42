/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:31:03 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/17 18:13:13 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	int		len_str;

	i = 0;
	len_str = 0;
	while (str[len_str])
		len_str++;
	while (len_str >= 0)
	{
		if (str[len_str] == (char)c)
			return ((char *)str + len_str);
		len_str--;
		i++;
	}
	return (NULL);
}

// int main() 
// {
//     const char *texte = "bonjour le monde!";
//     char *position = strrchr(texte, 'b');
//     char *position_1 = ft_strrchr(texte, 'b');

//    printf("%s", position_1);
//    printf("\n%s", position);
// }
