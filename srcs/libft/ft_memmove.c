/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:46:34 by fgaribot          #+#    #+#             */
/*   Updated: 2018/11/14 17:55:47 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (src > dst)
		while (++i < len)
			((char *)dst)[i] = ((const char*)src)[i];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
