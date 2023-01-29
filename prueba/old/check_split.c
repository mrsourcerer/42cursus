/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:09:49 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/11 13:58:09 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// prueba puntero de puntero
#include <stdlib.h>

char	**ft_split(char const *s, char c)
{
	size_t	*dict;
	char	*str0 = "separa";
	char	*str1 = "esto";

	dict = (size_t *)malloc(3 * sizeof(size_t));
	dict[0] = str0[0];
	dict[1] = str1[0];
	return (dict);
}

int	main(void)
{
	char **words;

	words = ft_split("separa esto", ' ');
}
