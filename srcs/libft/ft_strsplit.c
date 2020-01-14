/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:14:07 by fgaribot          #+#    #+#             */
/*   Updated: 2019/08/09 11:07:30 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if (!(tab = (char **)malloc(sizeof(*tab) * (ft_countsplit(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			if (!(tab[j] = (char *)malloc(sizeof(tab) *
							(ft_countchar(s + i, c) + 1))))
				return (NULL);
			ft_strcpc(tab[j++], (char *)(s + i), c);
			i = i + (ft_countchar(s + i, c));
		}
	}
	tab[j] = NULL;
	return (tab);
}
