/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:41:58 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/17 19:29:55 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *str, int cha, size_t n)
{
	unsigned char		c;
	unsigned char		*s;
	size_t				i;

	i = 0;
	s = (unsigned char *) str;
	c = (unsigned char) cha;
	while (i < n)
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
    const char str[] = "Hello, world!";
    int c = 'p';
    size_t n = 13;

    char *result = (char *)ft_memchr(str, c, n);
    if (result)
        printf("Caractère trouvé à la position : %d\n", result - str);
    else
        printf("Caractère non trouvé.\n");

    return 0;
}
*/