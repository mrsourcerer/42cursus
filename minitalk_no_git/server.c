/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 08:38:14 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/24 07:22:00 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h> // quitarlo en cuanto presente printf y lo incluya en libft***

void	ft_signal_received(int sig_num)
{
	if (sig_num == SIGUSR1)
		printf("1"); //ft_printf
	if (sig_num == SIGUSR2)
		printf("0"); //ft_printf
}

int	main(void)
{
	int	pid;

	signal(SIGUSR1, ft_signal_received);
	signal(SIGUSR2, ft_signal_received);
	pid = getpid();
	printf("pid: %i\n", pid); // ft_printf
	while (1)
	{
		usleep(1);
	}
	return (0);
}
