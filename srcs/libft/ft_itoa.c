/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:11:10 by fgaribot          #+#    #+#             */
/*   Updated: 2018/11/14 18:53:24 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		nb;
	int		neg;
	long	cp;

	cp = n;
	nb = ft_countdigits(n);
	i = 0;
	if (!(str = (char *)malloc(sizeof(*str) * (nb + 2))))
		return (NULL);
	neg = n < 0 ? -1 : 1;
	cp = n < 0 ? -cp : cp;
	while (nb-- > 0)
	{
		str[i++] = (cp % 10) + 48;
		cp = cp / 10;
	}
	if (neg < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
