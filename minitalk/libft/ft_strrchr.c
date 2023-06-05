/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:20:37 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/08 06:48:09 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = s;
	if (*p)
		while (*p)
			p++;
	while (p >= s)
	{
		if (*p == (char)c)
			return ((char *)p);
		p--;
	}
	return (0);
}
