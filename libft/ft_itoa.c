/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:11:32 by sshin             #+#    #+#             */
/*   Updated: 2016/12/27 07:54:18 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*nb;
	int		i;
	long	tmp;

	if (n <= 0)
		i = 1;
	else
		i = 0;
	tmp = n;
	while (n)
	{
		++i;
		n = n / 10;
	}
	if (!(nb = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	nb[i] = '\0';
	if (tmp <= 0)
		nb[0] = (tmp < 0) ? '-' : '0';
	while (tmp)
	{
		nb[--i] = (tmp < 0 ? -tmp : tmp) % 10 + '0';
		tmp = tmp / 10;
	}
	return (nb);
}
