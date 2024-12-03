/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:31:36 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/15 12:31:36 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
/*
int main()
{
    // Test avec sortie standard
    printf("Test sur la sortie standard:\n");
    ft_putendl_fd("Bonjour, monde!", STDOUT_FILENO);

    // Test avec sortie d'erreur
    printf("Test sur la sortie d'erreur:\n");
    ft_putendl_fd("Erreur: quelque chose ne va pas!", STDERR_FILENO);
}
*/