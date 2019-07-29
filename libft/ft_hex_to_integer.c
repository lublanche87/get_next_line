/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 21:27:08 by sshin             #+#    #+#             */
/*   Updated: 2016/12/30 18:51:38 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hex_to_integer(char *s)
{
	int n;
	int	sign;

	n = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\v'
			|| *s == '\f')
		++s;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (*s)
	{
		n = n * 16;
		if (*s >= 'A' && *s <= 'F')
			n = n + *s - 'A' + 10;
		else if (ft_isdigit(*s))
			n = n + *s - '0';
		else
			n = n + *s - 'a' + 10;
		++s;
	}
	return (n * sign);
}