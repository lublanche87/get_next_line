/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:30:18 by sshin             #+#    #+#             */
/*   Updated: 2016/11/27 22:26:25 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*sorc;
	char	*dest;

	sorc = (char*)src;
	dest = (char*)dst;
	i = 0;
	if (src > dst)
		while (i < len)
		{
			dest[i] = sorc[i];
			i++;
		}
	else
		while (i < len)
		{
			*(dest + len - 1) = *(sorc + len - 1);
			len--;
		}
	return (dst);
}
