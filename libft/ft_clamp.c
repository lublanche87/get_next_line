/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 03:42:53 by sshin             #+#    #+#             */
/*   Updated: 2016/12/27 03:48:59 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_clamp(int min, int max, int i)
{
	if (i < min)
		i = min	;
	if (i > max)
		i = max;
	return (i);
}
