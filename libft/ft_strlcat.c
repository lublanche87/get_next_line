/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 21:23:56 by sshin             #+#    #+#             */
/*   Updated: 2016/12/27 00:51:31 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	i;

	d = ft_strlen((char const*)dest);
	s = ft_strlen((char const*)src);
	if (!size)
		return (d);
	i = 0;
	while (*src && (i + d < size - 1))
		dest[i++ + d] = *src++;
	dest[i + d] = '\0';
	if (d < size)
		return (s + d);
	else
		return (s + size);
	return (0);
}
