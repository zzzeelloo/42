/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:42:03 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/16 17:08:56 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	y;
	size_t	size_d;
	size_t	size_s;

	i = 0;
	y = 0;
	size_d = ft_strlen(dest);
	size_s = ft_strlen((char *)src);
	while (dest[i] && i < size)
		i++;
	while (src[y] && (i + y + 1) < size)
	{
		dest[i + y] = src[y];
		y++;
	}
	if (i + y < size)
		dest[i + y] = '\0';
	if (size_d <= size)
		return (size_d + size_s);
	return (size_s + size);
}
// int main()
// {
//     char dest[30] = "a";
//     // const char *src = 
//     int z;
//     z = ft_strlcat(dest, "lorem", 15);
//     printf("Resultat : %s\n%d", dest,z);
// }