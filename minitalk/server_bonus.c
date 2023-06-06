/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 08:38:14 by danlopez          #+#    #+#             */
/*   Updated: 2023/06/05 07:01:53 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

int	g_i_c[2];

void	ft_signal_received(int sig_num)
{
	if (sig_num == SIGUSR1)
	{
		g_i_c[1] = g_i_c[1] | 1 << g_i_c[0];
	}
	g_i_c[0]--;
	if (g_i_c[0] == -1)
	{
		g_i_c[0] = 7;
		write(1, &g_i_c[1], 1);
		g_i_c[1] = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	g_i_c[0] = 7;
	g_i_c[1] = 0;
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
