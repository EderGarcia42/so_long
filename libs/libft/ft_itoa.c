/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:04:21 by edegarci          #+#    #+#             */
/*   Updated: 2024/12/02 14:09:44 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	i;
	int		len;
	char	*res;

	len = ft_num_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	i = n;
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (i == 0)
		res[0] = '0';
	if (i < 0)
	{
		res[0] = '-';
		i = -i;
	}
	while (i)
	{
		res[--len] = (i % 10) + '0';
		i /= 10;
	}
	return (res);
}
