/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:26:58 by sshin             #+#    #+#             */
/*   Updated: 2019/03/05 21:25:39 by sshin            ###   ########.fr       */
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
		if (ret <= 0)
			break ;
		buf[ret] = '\0';
		temp = str;
		str = ft_strjoin(str, buf);
		free(temp);
	}
	if (ret <= 0)
		(*line) = NULL;
	return ((ret >= 0) ? str : (char*)-1);
}

char		*ft_new_line(char **str)
{
	int		len;
	int		i;
	char	*ptr;
	char	*newline;

	ptr = ft_strchr(*str, '\n');
	if (ptr != NULL)
	{
		len = (ft_strlen(*str) - (ft_strlen(ptr)));
		newline = ft_strsub(*str, 0, len);
		ft_memmove(*str, *str + len + 1, (i = ft_strlen(*str + len + 1)));
		(*str)[i] = '\0';
	}
	else
	{
		newline = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	return (newline);
}

int			get_next_line(const int fd, char **line)
{
	static char		*str[FD];
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0 || fd >= FD)
		return (-1);
	str[fd] = read_line(fd, line, str[fd]);
	if (str[fd] < 0)
		return (-1);
	if (str[fd] && *(str[fd]) != '\0')
	{
		*line = ft_new_line(&(str[fd]));
		return (1);
	}
	*line = NULL;
	return (0);
}
