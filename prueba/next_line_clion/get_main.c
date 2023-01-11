/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 05:53:46 by danlopez          #+#    #+#             */
/*   Updated: 2023/01/11 07:08:33 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*fd_name = "only_nl.txt";
	char	*line;
	int		end;

	end = 0;
	printf("file: %s\n", fd_name);
	fd = open(fd_name, O_RDONLY);
	if (fd == -1)
		return (0);
	printf("Buffer_size: %i\n", BUFFER_SIZE);
	while (!end)
	{
		line = get_next_line(fd);
		if (!line)
			end = 1;
		else
		{
			printf("Linea: *%s*fin_linea\n", line);
			free(line);
		}
	}
	close(fd);
	return (0);
}
