/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:18:07 by edegarci          #+#    #+#             */
/*   Updated: 2024/12/02 17:52:10 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_and_store(int fd, char *storage)
{
	char	*buffer;
	int		readbytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readbytes = 1;
	while (!ft_strchr(storage, '\n') && readbytes > 0)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes < 0)
			return (free(buffer), free(storage), NULL);
		if (readbytes == 0 && (!storage || !storage[0]))
			return (free(buffer), free(storage), NULL);
		buffer[readbytes] = '\0';
		storage = ft_strjoin(storage, buffer);
		if (!storage)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (storage);
}

char	*leftover(char *storage)
{
	char	*leftover;
	int		i;
	int		j;

	if (!storage)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	leftover = malloc(sizeof(char) * (ft_strlen(storage) - i));
	if (!leftover)
		return (NULL);
	i++;
	j = 0;
	while (storage[i])
		leftover[j++] = storage[i++];
	leftover[j] = '\0';
	free(storage);
	return (leftover);
}

char	*create_line(char *storage)
{
	char	*line;
	int		i;

	if (!storage || !storage[0])
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + (storage[i] == '\n') + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	storage = read_and_store(fd, storage);
	if (!storage || !*storage)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	line = create_line(storage);
	storage = leftover(storage);
	return (line);
}
