/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherif <zcherif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:42:06 by zcherif           #+#    #+#             */
/*   Updated: 2024/11/18 14:50:38 by zcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int	count_cs(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	absolute_v(int n)
{
	if (n < 0)
		n = n * (-1);
	return (n);
}

char	*ft_itoa(int nbr)
{
	int		c_nbr;
	char	*tab;
	int		num;

	if (nbr == 0)
		return (ft_strdup("0"));
	else if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	c_nbr = count_cs(nbr);
	num = absolute_v(nbr);
	tab = (char *)ft_calloc((c_nbr + 1), sizeof(char));
	if (tab == NULL)
		return (NULL);
	tab[c_nbr] = '\0';
	if (nbr < 0)
		tab[0] = '-';
	while (num > 0)
	{
		if (c_nbr > 0)
			tab[--c_nbr] = (num % 10) + '0';
		else
			tab[c_nbr--] = (num % 10) + '0';
		num = num / 10;
	}
	return (tab);
}

// int main(void)
// {
// 	// int n = 58;
// 	// char * tab;

// 	// tab = ft_itoa(n);
// 	// printf("%s",tab);
// 	printf("%s", ft_itoa(58));
// }
