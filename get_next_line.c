/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 07:59:10 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/02 07:59:12 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_read_file(int fd, char *res)
{
	char	*buffer;
	int		readed;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	readed = 1;
	while (readed > 0)
	{
		readed = read (fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[readed] = 0;
		res = ft_drop_and_join(res, buffer);
		if (ft_strchr(buffer, '\n'))
		{
			free(buffer);
			return (res);
		}
	}
	free(buffer);
	return (res);
}

char	*ft_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_next_line(char *buffer)
{
}

char	*ft_drop_and_join(char *buffer, char *buf)
{
}

char	*get_next_line(int fd)

{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (0);
	line = ft_line(buffer);
}
