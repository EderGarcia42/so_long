/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:37:58 by edegarci          #+#    #+#             */
/*   Updated: 2024/12/02 14:11:05 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void	free_array(char **array, size_t count)
{
	while (count > 0)
	{
		count--;
		free(array[count]);
	}
	free(array);
}

static char	**split(char const *s, char c, char **array, size_t words_count)
{
	size_t	i;
	size_t	word_len;

	i = 0;
	while (i < words_count)
	{
		while (*s && *s == c)
			s++;
		word_len = get_word_len(s, c);
		array[i] = ft_substr(s, 0, word_len);
		if (!array[i])
		{
			free_array(array, i);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	if (!split(s, c, array, words))
		return (NULL);
	return (array);
}
