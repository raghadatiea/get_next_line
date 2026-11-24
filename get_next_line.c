/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratieh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:37:41 by ratieh            #+#    #+#             */
/*   Updated: 2026/11/24 15:37:42 by ratieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*my_free(char *saved, char *buffer)
{
	free(buffer);
	free(saved);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = read_file(fd, saved);
	if (!saved)
		return (NULL);
	line = get_line(saved);
	if (!line)
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	saved = get_remaining(saved);
	return (line);
}

char	*get_line(char *saved)
{
	char	*line;
	int		i;

	i = 0;
	if (!saved || !saved[0])
		return (NULL);
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		i++;
	line = ft_substr(saved, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_remaining(char *saved)
{
	char	*remain;
	int		i;

	i = 0;
	if (!saved)
		return (NULL);
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
	{
		free(saved);
		return (NULL);
	}
	remain = ft_substr(saved, i + 1, ft_strlen(saved) - i - 1);
	if (!remain)
	{
		free(saved);
		return (NULL);
	}
	free(saved);
	return (remain);
}

char	*read_file(int fd, char *saved)
{
	char	*buffer;
	ssize_t	read_bytes;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (my_free(saved, NULL));
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(saved, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (my_free(saved, buffer));
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(saved, buffer);
		if (!temp)
			return (my_free(saved, buffer));
		free(saved);
		saved = temp;
	}
	free(buffer);
	return (saved);
}
