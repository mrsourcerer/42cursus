/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 05:53:46 by danlopez          #+#    #+#             */
/*   Updated: 2023/01/03 15:18:55 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_next_line/get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		end;
	//int		i;

	end = 0;
	//i = 0;
	fd = open("text.txt", O_RDONLY);
    if (fd == -1)
        return (0);
    while (!end)
	{
		line = get_next_line(fd);
		if (!line)
			end = 1;
		else
			printf("Linea: ********\n%s\n***************\n", line);
		//i++;
	}
	close(fd);
	return (0);
}
