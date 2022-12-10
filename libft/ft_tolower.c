/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:48:03 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/10 13:28:00 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isupper(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    else
        return (0);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	else
		return (c);
}
