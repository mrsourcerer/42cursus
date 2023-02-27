/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:33:14 by danlopez          #+#    #+#             */
/*   Updated: 2023/02/27 07:23:15 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	ft_send_char(pid_t pid, int c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		ft_printf("dentro, i: \n", i);
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
	}
}

void	ft_send_str(pid_t pid, char *str)
{
	//ft_putstr(str, 1);
	//ft_putstr("\n", 1);
	//kill(pid, sig_num);
	while (*str)
	{
		ft_send_char(pid, *str);
		str++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t		pid;
	char		*str;
	sigset_t	signal_set;

	if (argc < 3)
		return (1);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	ft_printf("Num: %i\n", pid);
	ft_printf("str: %s\n", str);
	sigemptyset(&signal_set);
	sigaddset(&signal_set, SIGUSR1);
	sigaddset(&signal_set, SIGUSR2);

	ft_send_str(pid, str);
	return (0);
}
