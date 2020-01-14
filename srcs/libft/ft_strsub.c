/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 22:22:11 by fgaribot          #+#    #+#             */
/*   Updated: 2018/11/14 18:15:13 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	while (i < (unsigned int)len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
