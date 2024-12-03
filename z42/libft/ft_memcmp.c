/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:41:54 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/18 14:53:35 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str1;
	size_t			i;

	i = 0;
	str = (unsigned char *)ptr1;
	str1 = (unsigned char *)ptr2;
	while (i < n)
	{
		if (str[i] != str1[i])
			return ((unsigned char)str[i] - (unsigned char)str1[i]);
		i++;
	}
	return (0);
}
/*
int main() 
{
    char str1[] = "Hello";
    char str2[] = "Helpo";

    int result = ft_memcmp(str1, str2, 5);

    if (result == 0)
        printf("The strings are equal.\n");
    else
        printf("The strings are different.\n");
}
*/