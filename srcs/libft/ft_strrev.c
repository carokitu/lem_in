/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:38:04 by fgaribot          #+#    #+#             */
/*   Updated: 2018/11/15 09:59:51 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrev(char *str)
{
	int		n;
	int		i;
	char	rev;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		i++;
	}
	n = i - 1;
	i = 0;
	while (i < n)
	{
		rev = str[i];
		str[i] = str[n];
		str[n] = rev;
		i++;
		n--;
	}
	return (str);
}
