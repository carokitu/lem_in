/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:51:02 by fgaribot          #+#    #+#             */
/*   Updated: 2018/11/12 19:28:00 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;

	if (!(dest = malloc(sizeof(*s1) * (ft_strlen(s1) + 1))))
		return (NULL);
	ft_strcpy(dest, s1);
	return (dest);
}
