/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:38:36 by danlopez          #+#    #+#             */
/*   Updated: 2022/12/10 13:26:58 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_islower(int c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    else
        return (0);
}

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	else
		return (c);
}
