/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:41:29 by asebrani          #+#    #+#             */
/*   Updated: 2024/06/13 17:41:32 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_function(int fd, char *save)
{
	char		*buffer;
	ssize_t		nb;

	if (!save)
		save = ft_callocc(1, 1);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	nb = 1;
	while (nb)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nb] = '\0';
		save = ft_strjoinn(save, buffer);
		if (ft_strchrr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (save);
}

char	*ft_line(char *save)
{
	char	*line;
	int		count;
	int		j;

	count = 0;
	j = -1;
	if (!save[count])
		return (NULL);
	while (save[count] && save[count] != '\n')
		count++;
	if (save[count] == '\n')
		count++;
	line = ft_callocc(count + 1, sizeof(char));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	while (++j < count)
		line[j] = save[j];
	return (line);
}

char	*ft_rest(char *save)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	rest = ft_callocc((ft_strlenn(save + i) + 1), sizeof(char));
	if (!rest)
	{
		free(rest);
		return (NULL);
	}
	i++;
	j = 0;
	while (save[i])
		rest[j++] = save[i++];
	free(save);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(save), save = NULL, NULL);
	save = ft_read_function(fd, save);
	if (!save)
		return (NULL);
	line = ft_line(save);
	save = ft_rest(save);
	return (line);
}
