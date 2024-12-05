/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:39:10 by edegarci          #+#    #+#             */
/*   Updated: 2024/12/02 14:11:56 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*subs;

	if (!s)
		return (NULL);
	i = 0;
	while (i < len && start < ft_strlen(s) && s[start + i])
		i++;
	j = 0;
	subs = malloc((i + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	while (j < i && start < ft_strlen(s))
	{
		subs[j] = s[start + j];
		j++;
	}
	subs[i] = '\0';
	return (subs);
}
