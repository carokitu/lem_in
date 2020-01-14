/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 08:06:26 by fgaribot          #+#    #+#             */
/*   Updated: 2018/11/14 18:59:03 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		a;

	if (!s)
		return (NULL);
	a = 0;
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j])
		j++;
	j = j - 1;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j > i)
		j--;
	if (!(str = (char *)malloc(sizeof(*str) * (j - i + 2))))
		return (NULL);
	while (i <= j)
		str[a++] = s[i++];
	str[a] = '\0';
	return (str);
}
