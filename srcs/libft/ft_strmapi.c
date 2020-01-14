/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:35:37 by fgaribot          #+#    #+#             */
/*   Updated: 2018/11/14 18:12:01 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = -1;
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	while (++i < len)
		str[i] = f(i, s[i]);
	str[i] = '\0';
	return (str);
}
