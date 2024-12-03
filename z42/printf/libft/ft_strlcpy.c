/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:42:09 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/16 17:10:27 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t count)
{
	size_t	i;

	i = 0;
	if (count == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	else
	{
		while (src[i] && i < count - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		i = 0;
		while (src[i])
			i++;
		return (i);
	}
}
/*
int main(void)
{
    char str[20];
    char src[] = "Je suis le boss";
    int z = 0;

    z = ft_strlcpy(str, src, 5);
    printf("%s\n%d", str, z);
}
*/