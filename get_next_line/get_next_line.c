/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:23:15 by danlopez          #+#    #+#             */
/*   Updated: 2023/01/26 06:36:16 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buffer(int fd)
{
	char	*buf;
	ssize_t	size_read;
	char	*tmp;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	size_read = read (fd, buf, BUFFER_SIZE);
	if (size_read == -1)
		return (ft_free(&buf), NULL);
	if (size_read == 0)
	{
		ft_free(&buf);
		//buf = ft_get("", 0, -1);
		return (buf);
	}
	if (size_read < BUFFER_SIZE)
	{
		tmp = ft_get(buf, 0, (int)size_read);
		ft_free(&buf);
		buf = tmp;
	}
	else
		buf[BUFFER_SIZE] = '\0';
	return (buf);
}

char	*ft_str(char **str, char **buffer)
{
	char	*tmp;
	size_t	size;
	char	*empty;

	empty = ft_get("", 0, 0);
	size = ft_strlen(*str) + ft_strlen(*buffer);
	tmp = (char *)malloc((size + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	if (*str == NULL)
		tmp = ft_join(&empty, buffer);
	else
		tmp = ft_join(str, buffer);
	*str = tmp;
	tmp = NULL;
	ft_free(&empty);
	return (*str);
}

char	*ft_line(char **str)
{
	char	*line;
	char	*tmp;
	int		nl;

	nl = ft_check(*str, '\n');
	line = ft_get(*str, 0, nl);
	if ((int)ft_strlen(*str) > nl)
		tmp = ft_get(*str, nl + 1, (int)ft_strlen(*str));
	else
		tmp = ft_get("", 0, 0);
	ft_free(str);
	*str = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (1)
	{
		if (ft_check(str, '\n') >= 0)
			return (line = ft_line(&str), line);
		buffer = ft_buffer(fd);
		if (buffer)
			str = ft_str(&str, &buffer);
		else
		{
			if (ft_strlen(str))
			{
				line = str;
				str = NULL;
				return (line);
			}
			else
				return (ft_free(&str), NULL);
		}
	}
}
