/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:26:58 by sshin             #+#    #+#             */
/*   Updated: 2019/07/30 01:02:36 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*read_line(const int fd, char **line, char *str)
{
	int		ret;
	char	*temp;
	char	buf[BUFF_SIZE + 1];

	ret = 1;
	ft_bzero(buf, BUFF_SIZE + 1);
	while ((ft_strchr(buf, '\n') == NULL) && ret)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == 0)
			break ;
		buf[ret] = '\0';
		temp = str;
		str = ft_strjoin(str, buf);
		free(temp);
	}
	if (ret == 0)
		(*line) = NULL;
	return (str);
}

char		*ft_new_line(const int fd, char **str)
{
	int		len;
	int		i;
	char	*ptr;
	char	*newline;

	ptr = ft_strchr(str[fd], '\n');
	if (ptr != NULL)
	{
		len = (ft_strlen(str[fd]) - (ft_strlen(ptr)));
		newline = ft_strsub(str[fd], 0, len);
		i = ft_strlen(str[fd] + len + 1);
		ft_memmove(str[fd], str[fd] + len + 1, i);
		(str[fd])[i] = '\0';
	}
	else
	{
		newline = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
	}
	return (newline);
}

int			get_next_line(const int fd, char **line)
{
	static char		*str[FD];
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	str[fd] = read_line(fd, line, str[fd]);
	if (str[fd] && *(str[fd]) != '\0')
	{
		*line = ft_new_line(fd, str);
		return (1);
	}
	(*line) = NULL;
	return (0);
}
