/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:23:15 by danlopez          #+#    #+#             */
/*   Updated: 2023/01/21 21:29:04 by danlopez         ###   ########.fr       */
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
	{
		free(buffer);
		buffer = NULL;
	}
	str = tmp;
	tmp = NULL;
	return (str);
}

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	char	*tmp;
	ssize_t	size_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	size_read = read(fd, buffer, BUFFER_SIZE);
	if (size_read == -1)
	{
		if (str)
			return (free(buffer), buffer = NULL, str[0] = '\0', (char *) 0);
		else
			size_read = 0;
	}
	if (size_read == 0)
		return (free(buffer), buffer = NULL, (char *)0);
	buffer[size_read] = '\0';
	if (size_read < BUFFER_SIZE)
	{
		tmp = ft_substr(buffer, 0, size_read);
		free(buffer);
		buffer = tmp;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*str;
	char		*line;

	//buffer = NULL;
	//line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (ft_check_end(str) == -1)
	{
		buffer = ft_read(fd, str);
		if (!buffer)
		{
			if (ft_strlen(str) > 0)
			{
				line = ft_substr(str, 0, ft_strlen(str));
				return (free(str), str = NULL, line);
			}
			else
				return (free(str), str = NULL, (char *) 0);
		}
		else
			str = ft_makestr(buffer, str);
		buffer = NULL;
	}
	line = ft_substr(str, 0, ft_check_end(str) + 1);
	return (str = ft_delete(str, ft_check_end(str)), line);
}
