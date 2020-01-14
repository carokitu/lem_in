/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:40:12 by fgaribot          #+#    #+#             */
/*   Updated: 2018/11/08 17:37:52 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dst_size;
	unsigned int	src_size;
	unsigned int	j;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	j = 0;
	if (size <= dst_size)
		return (src_size + size);
	while (src[j] && j < size - dst_size - 1)
	{
		dst[dst_size + j] = src[j];
		j++;
	}
	dst[dst_size + j] = '\0';
	return (dst_size + src_size);
}
