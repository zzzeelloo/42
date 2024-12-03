/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:25:59 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/16 17:11:49 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char example_transform(unsigned int i, char c)
{
    if (i % 2 == 0)
        return (c >= 'a' && c <= 'z') ? c - 32 : c; 
    else
        return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

int main(void)
{
    char str[] = "Hello World!";
    char *result;

    // Utilise ft_strmapi pour transformer str
    result = ft_strmapi(str, example_transform);

    // Vérifie si la transformation s'est bien passée
    if (result)
    {
        printf("Chaîne d'origine : %s\n", str);
        printf("Chaîne transformée : %s\n", result);
        free(result); // Libère la mémoire allouée
    }
    else
    {
        printf("Erreur d'allocation de mémoire\n");
    }

    return 0;
}
*/