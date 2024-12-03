/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:42:17 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/16 16:39:47 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *pointer, size_t count)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)pointer;
	while (i < count)
	{
		str[i] = '\0';
		i++;
	}
}
