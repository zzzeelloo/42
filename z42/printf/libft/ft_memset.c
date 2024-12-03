/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:27:47 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/16 16:55:27 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) pointer;
	while (i < count)
	{
		str[i] = (unsigned char)value;
		i++;
	}
	return ((void *)str);
}
// int main (void)
// {
//     char z[5];
//     printf("%s", (char*)ft_memset(z, 'A', 4));
// }