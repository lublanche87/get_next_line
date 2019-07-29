/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:50:03 by sshin             #+#    #+#             */
/*   Updated: 2016/12/27 01:00:04 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	while (n--)
		if (*(unsigned char *)ptr++ == (unsigned char)c)
			return ((unsigned char *)ptr - 1);
	return (NULL);
}
