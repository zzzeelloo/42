/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:25:42 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/16 17:07:27 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void to_uppercase(unsigned int i, char *c)
{
    (void)i; // On ignore l'indice dans cet exemple
    if (c && *c)
        *c = ft_toupper(*c);
}

int main()
{
    char str[] = "hello world";
    printf("Avant ft_striteri : %s\n", str);

    ft_striteri(str, to_uppercase);

    printf("Après ft_striteri : %s\n", str); // Devrait afficher : "HELLO WORLD"
    return 0;
}
*/