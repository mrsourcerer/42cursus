/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:33:14 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/22 07:24:01 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h> // quitar en cuanto presente printf y lo integre ***********************

void	ft_send_str(int pid, int sig_num, char *str)
{
	return ;
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;

	if (argc < 3)
		return (1);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	printf("Num: %i\n", pid);
	printf("str: %s\n", str);
	kill(pid, SIGUSR1);
	ft_send_str(pid, SIGUSR1, str);
	return (0);
}
