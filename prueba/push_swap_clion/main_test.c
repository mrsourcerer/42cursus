/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:43:57 by danlopez          #+#    #+#             */
/*   Updated: 2023/05/29 20:20:27 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (ft_isdigit(*(argv[1])))
			ft_printf("%c is digit\n", *(argv[1]));
		else
			ft_printf("%c is NOT digit\n", *(argv[1]));
	}
	return (0);
}
