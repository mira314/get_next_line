/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 08:15:20 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/03 13:26:39 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_fill(int fd, char *readed, char *buffer)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(readed);
			return (0);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (!readed)
			readed = ft_strdup("");
		temp = readed;
		readed = ft_strjoin(temp, buffer);
		free (temp);
		temp = 0;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (readed);
}

char	*ft_set_line(char *line)
{
	char	*readed;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[1] == 0)
		return (0);
	readed = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*readed == 0)
	{
		free(readed);
		readed = 0;
	}
	line[i + 1] = 0;
	return (readed);
}

char	*get_next_line(int fd)
{
	static char	*readed[MAX_FD];
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(readed[fd]);
		readed[fd] = 0;
		buffer = 0;
		return (0);
	}
	if (!buffer)
		return (0);
	line = ft_fill(fd, readed[fd], buffer);
	free(buffer);
	buffer = 0;
	if (!line)
		return (0);
	readed[fd] = ft_set_line(line);
	return (line);
}
