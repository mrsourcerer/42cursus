/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 05:53:46 by danlopez          #+#    #+#             */
/*   Updated: 2023/01/18 06:05:27 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int			fd;
	char		*fd_name = "1char.txt";
	char		*line;
	int			end;
	//int			i;

	//i = 0;
	end = 0;
	printf("file: %s\n", fd_name);
	/*fd = open(fd_name, O_RDONLY);
	if (fd == -1)
		return (0);
	printf("Buffer_size: %i\n", BUFFER_SIZE);
	while (i < 4)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("Especial inicio_linea: *%s*fin_linea\n", line);
			free(line);
		}
		i++;
		if (i == 3)
			close(fd);
	}
	end = 0;*/
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
			printf("inicio_linea: *%s*fin_linea\n", line);
			free(line);
		}
	}
	close(fd);
	return (0);
}
