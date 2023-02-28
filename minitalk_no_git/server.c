/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 08:38:14 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/28 07:25:40 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	ft_signal_received(int sig_num, int *i, char *char_bin)
{
	if (sig_num == SIGUSR1)
	{
		//ft_printf("1");
		char_bin[*i] = "1";
	}
	if (sig_num == SIGUSR2)
	{
		//ft_printf("0");
	}
}

int	main(void)
{
	pid_t	pid;
	int		i;
	char	char_bin[8];

	i = 0;
	signal(SIGUSR1, (void (*)(int, int*, char*)) ft_signal_received);
	//signal(SIGUSR1, ft_signal_received);
	signal(SIGUSR2, ft_signal_received);
	pid = getpid();
	ft_printf("pid: %i\n", pid);
	while (1)
	{
		usleep(1);
	}
	return (0);
}
