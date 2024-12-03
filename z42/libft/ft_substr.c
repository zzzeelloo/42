/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:30:50 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/25 14:01:10 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			y;
	unsigned char	*str;

	y = ft_strlen(s);
	if (start > y)
		return (ft_strdup(""));
	if (len > y - start)
		len = y - start;
	str = malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	y = 0;
	while (y < len)
	{
		str[y] = s[start + y];
		y++;
	}
	str[y] = '\0';
	return ((char *)str);
}

// int main (void)
// {
//     char *str = "abcdef";
//     char *str1;

//     str1 = ft_substr(str, 0, 5);
//     printf("%s", str1);

// }
