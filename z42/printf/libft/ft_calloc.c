/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:32:20 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/17 17:04:12 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*mem;
	size_t			i;

	i = 0;
	mem = malloc((size * num));
	if (mem == NULL)
		return (0);
	ft_bzero(mem, size * num);
	return (mem);
}
/*
int main() {
    int *array = (int*) ft_calloc(5, sizeof(int));

    if (array != NULL) {
        for (int i = 0; i < 5; i++) 
        {
            printf("%d ", array[i]);
        }
        free(array);
    } else {
        printf("Allocation failed");
    }
}
*/