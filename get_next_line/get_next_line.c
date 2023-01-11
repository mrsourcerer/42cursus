/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:23:15 by danlopez          #+#    #+#             */
/*   Updated: 2023/01/11 07:22:29 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_end(char *str)
{
	char	*nl;

	if (!str)
		return (-1);
	nl = ft_strchr(str, '\n');
	if (nl)
		return ((int)(ft_strlen(str) - ft_strlen(nl)));
	return (-1);
}

char	*ft_delete(char *str, int pos)
{
	size_t	size;
	char	*tmp;

	size = ft_strlen(str);
	tmp = ft_substr(str, pos + 1, size - pos - 1);
	free(str);
	str = tmp;
	return (str);
}

char	*ft_makestr(char *buffer, char *str)
{
	char	*tmp;
	size_t	size;

	size = ft_strlen(str) + ft_strlen(buffer);
	tmp = (char *)malloc((size + 1) * sizeof(char));
	if (!tmp)
		return (0);
	tmp[size] = '\0';
	ft_memcpy(tmp, str, ft_strlen(str));
	ft_memcpy(tmp + ft_strlen(str), buffer, ft_strlen(buffer));
	if (str)
		free(str);
	if (buffer)
		free(buffer);
	str = tmp;
	return (str);
}

char	*ft_read(int fd)
{
	char	*buffer;
	char	*tmp;
	ssize_t	size_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	size_read = read(fd, buffer, BUFFER_SIZE);
	if (size_read < 1)
		return (free(buffer), (char *)0);
	if (size_read < BUFFER_SIZE)
	{
		tmp = ft_substr(buffer, 0, size_read);
		free(buffer);
		buffer = tmp;
	}
	buffer[size_read] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*str;
	char		*line;

	if (fd == -1)
		return (0);
	line = NULL;
	while (ft_check_end(str) == -1)
	{
		buffer = ft_read(fd);
		if (!buffer)
		{
			if (ft_strlen(str) > 0)
			{
				line = ft_substr(str, 0, ft_strlen(str));
				return (free(str), str = NULL, line);
			}
			else
				return ((char *) 0);
		}
		else
			str = ft_makestr(buffer, str);
	}
	line = ft_substr(str, 0, ft_check_end(str) + 1);
	return (str = ft_delete(str, ft_check_end(str)), line);
}
