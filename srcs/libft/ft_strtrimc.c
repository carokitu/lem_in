/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:24:45 by fgaribot          #+#    #+#             */
/*   Updated: 2018/12/12 14:14:07 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char *s, char c)
{
	int		i;
	int		j;
	int		a;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	a = 0;
	while (s[i] == c)
		i++;
	while (s[j])
		j++;
	j = j - 1;
	while (s[j] == c && j > i)
		j--;
	while (i <= j)
		s[a++] = s[i++];
	s[a] = '\0';
	return (s);
}
