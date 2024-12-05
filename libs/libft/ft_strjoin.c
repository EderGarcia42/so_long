/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:47:42 by edegarci          #+#    #+#             */
/*   Updated: 2024/12/02 15:51:26 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *storage, const char *buffer)
{
	int		i;
	int		j;
	char	*str;

	if (!storage)
	{
		storage = (char *)malloc(1 * sizeof(char));
		storage[0] = '\0';
	}
	if (!storage || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(storage) + ft_strlen(buffer) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (storage[++i])
		str[i] = storage[i];
	while (buffer[j])
		str[i++] = buffer[j++];
	str[i] = '\0';
	free(storage);
	return (str);
}
