/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:50:47 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/16 16:43:36 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
/*
int main (void)
{
    char c = ')';
    int z = 0;

    z = ft_isalnum(c);
    printf("%d", z);
}
*/