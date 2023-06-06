/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:33:14 by danlopez          #+#    #+#             */
/*   Updated: 2023/06/06 06:41:26 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

char	*g_str;

void	ft_send_char(pid_t pid, int c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		usleep(120);
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
	}
}

void	ft_send_str(pid_t pid)
{
	while (*g_str)
	{
		ft_send_char(pid, *g_str);
		g_str++;
	}
	ft_send_char(pid, '\n');
}

int	ft_no_ok(char *str_num)
{
	if (ft_atoi(str_num) != ft_atol(str_num))
		return (-1);
	while (*str_num)
	{
		if (!ft_isdigit(*str_num))
			return (-1);
		str_num++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	pid_t		pid;
	sigset_t	signal_set;

	if (argc != 3)
		return (-1);
	if (ft_no_ok(argv[1]))
		return (-1);
	pid = ft_atoi(argv[1]);
	g_str = argv[2];
	ft_printf("Num: %i\n", pid);
	ft_printf("str: %s\n", g_str);
	sigemptyset(&signal_set);
	sigaddset(&signal_set, SIGUSR1);
	sigaddset(&signal_set, SIGUSR2);
	ft_send_str(pid);
	return (0);
}
