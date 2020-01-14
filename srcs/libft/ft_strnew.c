/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:05:37 by fgaribot          #+#    #+#             */
/*   Updated: 2018/11/12 19:21:13 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s1;

	if (!(s1 = malloc(size + 1)))
		return (NULL);
	ft_memset((void *)s1, '\0', size + 1);
	return (s1);
}
