/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:57:06 by fgaribot          #+#    #+#             */
/*   Updated: 2018/11/15 11:03:09 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float		ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (1 / ft_recursive_power(nb, -power));
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}
