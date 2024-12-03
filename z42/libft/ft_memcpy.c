/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:31:52 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/18 14:49:34 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	char		*str;
	const char	*str_src;
	size_t		i;

	i = 0;
	str = (char *)dest;
	str_src = (const char *)src;
	if (count == 0)
		return (str);
	if (!str && !str_src)
		return (NULL);
	if (count != 0)
	{
		while (i < count)
		{
			str[i] = str_src[i];
			i++;
		}
	}
	return ((unsigned char *)str);
}

// int main (void)
// {
//     char z[5];
//     char y[5] = "Zack";

//     ft_memcpy(((void*)0), ((void*)0), 0);
// }