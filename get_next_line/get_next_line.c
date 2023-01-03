/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:23:15 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/27 10:47:24 by danlopez         ###   ########.fr       */
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

void	ft_delete(char *str, int pos)
{
	size_t	size;
	size_t	i;

	size = ft_strlen(str);
	i = 0;
	while (i < size - pos - 1)
	{
		str[i] = str[i + pos + 1];
		i++;
	}
	str[i] = '\0';
}

char	*ft_makestr(char *buffer, char *str)
{
	char	*tmp;
	size_t	size;

	size = ft_strlen(str) + ft_strlen(buffer);
	tmp = (char *)malloc((size + 1) * sizeof(char));
	if (!tmp)
		return (0);
	ft_memcpy(tmp, str, ft_strlen(str));
	ft_memcpy(tmp + ft_strlen(str), buffer, ft_strlen(buffer));
	tmp[size] = '\0';
	free(str);
	free(buffer);
	str = tmp;
	return (str);
}

char	*ft_read(int fd)
{
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	if (!read(fd, buffer, BUFFER_SIZE))
		return (0);
	buffer[BUFFER_SIZE] = '\0';
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
			return (0);
		str = ft_makestr(buffer, str);
	}
	line = ft_substr(str, 0, ft_check_end(str));
	ft_delete(str, ft_check_end(str));
	return (line);
}
