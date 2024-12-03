/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:42:01 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/17 20:29:29 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]) && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

//  int main() 
// {
//     // const char *str1 = "bonjour";
//     // const char *str2 = "bonsoir";
//     // int z = 0;

//     // z = ft_strncmp(str1, str2, 5);
//     // printf("%d", z);
//  	printf("%d", ft_strncmp("test\200", "test\0", 6));
// }
