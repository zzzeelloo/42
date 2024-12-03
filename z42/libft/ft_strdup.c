/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:25:50 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/16 17:23:03 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *str)
{
	int		i;
	int		size_tab;
	char	*tab;

	i = 0;
	size_tab = ft_strlen(str);
	tab = 0;
	tab = malloc(sizeof(char) * (size_tab + 1));
	if (tab == 0)
		return (0);
	while (str[i])
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
/*
int main(void)
{
	char tab1[] = "Kiio";
	char *tab2 = "hehe";

	tab2 = str_dup(tab1);

	printf("%s", tab2);
}
*/