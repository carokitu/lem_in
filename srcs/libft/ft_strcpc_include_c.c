/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpc_include_c.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:09:24 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/04 16:54:07 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpc_include_c(char *dest, char *src, char c)
{
	int		i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		if (src[i++] == c)
			break ;
	}
	dest[i] = '\0';
	return (dest);
}
