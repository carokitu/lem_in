/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:18:50 by fgaribot          #+#    #+#             */
/*   Updated: 2018/11/14 18:11:21 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		str[i] = f(s[i]);
	str[i] = '\0';
	return (str);
}
