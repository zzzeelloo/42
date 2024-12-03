/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:42:12 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/13 11:42:12 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//oublie pas le header

#include <stdio.h>
#include "libft.h"

unsigned char	*ft_strncpy(unsigned char *dest,
					const unsigned char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			dest[i] = src[i];
		}
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	d = (unsigned char *) dest;
	s = (const unsigned char *)src;
	if (!d && !s)
		return (NULL);
	d = ft_strncpy(d, s, n);
	return (dest);
}

// int main()
// {
//     char str[] = "Hello, world!";
//     printf("Avant ft_memmove : %s\n", str);
//     ft_memmove(str + 7, str, 5);  
//     printf("Après ft_memmove : %s\n", str);

//     // Test sans chevauchement en copiant dans une autre chaîne
//     char dest[20] = "Initial text";
//     ft_memmove(dest, str, 12);
//     printf("Après copie sans chevauchement : %s\n", dest);

//     return 0;
// }