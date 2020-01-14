/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:20:35 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/03 19:23:32 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_countdigits_base(long long n, int base)
{
	int		count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n != 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}
