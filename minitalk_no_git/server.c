/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 08:38:14 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/02 07:01:05 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	ft_signal_received(int sig_num)
{
	static int	i = 7;
	static int	c = 0;

	//ft_printf("inside ft_signal_received\n");
	if (sig_num == SIGUSR1)
	{
		//ft_printf("1");
		c = c | 1 << i;
	}
	//if (sig_num == SIGUSR2)
	//{
		//ft_printf("0");
	//	c <<= 0;
	//}
	//ft_printf("i: %i, incompleta c: %c\n", i, c);
	i--;
	if (i == -1)
	{
		i = 7;
		//ft_printf("Printing...\n");
		ft_printf("%c", c);
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	signal(SIGUSR1, ft_signal_received);
	signal(SIGUSR2, ft_signal_received);
	pid = getpid();
	ft_printf("pid: %i\n", pid);
	while (1)
	{
		usleep(0);
	}
	return (0);
}
