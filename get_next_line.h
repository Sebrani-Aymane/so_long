/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:17:48 by asebrani          #+#    #+#             */
/*   Updated: 2024/06/14 23:32:58 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "so_long.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		ft_strlenn(char *str);
char	*ft_strjoinn(char *s1, char *s2);
char	*ft_strchrr(char *string, int c );
void	ft_bzeroo(void *s, size_t n);
void	*ft_callocc(size_t count, size_t size);
char	*get_next_line(int fd);

#endif
