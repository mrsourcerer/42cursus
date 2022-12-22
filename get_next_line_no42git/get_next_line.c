/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:23:15 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/22 07:28:52 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_end(char *str)
{
	char	*nl;

	nl = ft_strchr(str, '\n');
	if (*nl)
		return (ft_strlen(str) - ft_strlen(nl));
	return (-1);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*str;
	char 		*line;

	if (!str)
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (0);
		if (!read(fd, buffer, BUFFER_SIZE))
			return (0);
		str = ft_strdup(buffer);
		free(buffer);
	}
	if (ft_check_end(str) >= 0)
		line = ft_substr(str, 0, ft_check_end(str));
		//str = lo que queda menos line 
	return (line);
}
