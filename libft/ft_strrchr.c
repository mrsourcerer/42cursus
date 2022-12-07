/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:20:37 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/07 20:29:06 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	if (*s)
	{
		while (*s)
			s++;
		s--;
	}
	
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}
