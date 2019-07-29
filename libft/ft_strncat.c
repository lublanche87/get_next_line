/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:08:20 by sshin             #+#    #+#             */
/*   Updated: 2016/12/03 16:45:50 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (dest[j])
		j++;
	while (src[++i] && n--)
		dest[i + j] = src[i];
	dest[i + j] = '\0';
	return (dest);
}
