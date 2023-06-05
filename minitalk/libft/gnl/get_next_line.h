/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:17:19 by danlopez          #+#    #+#             */
/*   Updated: 2023/03/03 07:08:27 by danlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

char	*get_next_line(int fd);
int		ft_check(const char *str, char c);
void	ft_free(char **s);
char	*ft_join(char **s1, char **s2);
char	*ft_get(char *s, int start, int end);

#endif
