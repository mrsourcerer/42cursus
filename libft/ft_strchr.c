/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:28:09 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/07 07:24:12 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((void *)0);
}

#include <stdio.h>
#include <string.h>

int main(void)
{
	char *o;
	char *c;

	o = strchr("teste",'\0');
	c = ft_strchr("teste",'\0');
	printf("%c %p\n", *o, o);
	printf("%c %p\n", *c, c);
}
