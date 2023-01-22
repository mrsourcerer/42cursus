/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:23:15 by danlopez          #+#    #+#             */
/*   Updated: 2023/01/22 13:19:49 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buffer(int fd)
{
	char	*buf;
	ssize_t	size_read;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	size_read = read (fd, buf, BUFFER_SIZE);
	if (size_read == -1)
		return (free(buf), NULL);
	if (size_read == 0)
	{
		free(buf);
		buf = (char *) malloc(1);
		buf[0] = '\0';
		return (buf);
	}
	if (size_read < BUFFER_SIZE)
		buf[size_read] = '\0';
	else
		buf[BUFFER_SIZE] = '\0';
	return (buf);
}

int	ft_str(int fd, char **str)
{
	char	*buffer;
	char	*tmp;
	size_t	size;
	size_t	i;

	buffer = ft_buffer(fd);
	if (!buffer)
		return (-1);
	if (buffer[0] == '\0')
		return (1);
	size = ft_strlen(*str) + ft_strlen(buffer);
	tmp = (char *)malloc((size + 1) * sizeof(char));
	if (!tmp)
		return (-1);
	i = 0;
	while (i < size)
	{
		if (i < ft_strlen(*str))
			tmp[i] = *str[i];
		else
			tmp[i] = buffer[i - ft_strlen(*str)];
		i++;
	}
	tmp[size] = '\0';
	if (*str)
		free(*str);
	*str = tmp;
	return (free(buffer), buffer = NULL, 0);
}

char	*ft_line(int fd, char *str)
{
	char	*line;
	int		fd_empty;

	fd_empty = 0;
	while (ft_check(str, '\n') == -1 && !fd_empty)
	{
		fd_empty = ft_str(fd, &str);
		if (fd_empty == -1)
			return (NULL);
	}
	if (!str)
		return (NULL);
	if (fd_empty)
		return (str);
	else
		line = ft_subs(&str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_line(fd, str);
	if (line)
		return (line);
	return (NULL);
}
