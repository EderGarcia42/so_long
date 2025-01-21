/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:58:55 by edegarci          #+#    #+#             */
/*   Updated: 2025/01/20 18:37:15 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_line(int fd)
{
	char	*line;
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	int		i;

	line = (char *)malloc(10000);
	if (!line)
		return (NULL);
	i = 0;
	while ((bytes_read = read(fd, buffer, 1)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (buffer[0] == '\n' || buffer[0] == '\0')
			break ;
		line[i++] = buffer[0];
	}
	line[i] = '\0';
	if (bytes_read <= 0 && i == 0)
		{
			free(line);
			return (NULL);
		}
	return (line);
}
