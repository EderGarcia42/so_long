/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:56:36 by edegarci          #+#    #+#             */
/*   Updated: 2024/12/02 14:10:40 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_ptr;
	const char	*src_ptr;

	dst_ptr = (char *)dst;
	src_ptr = (const char *)src;
	if (!dst && !src)
		return (NULL);
	if (src_ptr < dst_ptr)
		while (len-- > 0)
			dst_ptr[len] = src_ptr[len];
	else
		while (len-- > 0)
			*dst_ptr++ = *src_ptr++;
	return (dst);
}
