/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:41:46 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/25 13:57:27 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < n)
	{
		if (big[i] == little[y])
		{
			while (big[i + y] == little[y] && i + y < n)
			{
				if (little[y +1] == '\0')
					return ((char *)big + i);
				y++;
			}
		}
		y = 0;
		i++;
	}
	return (NULL);
}

// int main() {
//     // const char *str = "Hello, world!";
//     // const char *sub = "world";
//     // char *result = ft_strnstr(str, sub, 10);

//     // if (result) {
//     //     printf("Sous-chaîne trouvée: %s\n", result);
//     // } else {
//     //     printf("Sous-chaîne non trouvée\n");
//     // }

//     // return 0;
// 	//printf("%s",ft_strnstr("lorem ipsum dolor sit amet", "ips", 10));
// }
