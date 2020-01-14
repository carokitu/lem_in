/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_print_base_anex.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:58:56 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/04 23:59:47 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(t_data_pf *data, int j)
{
	if (data->spe == 'p')
	{
		ft_putstr("0x");
		data->i += 2;
	}
	if (j == 0 && data->spe == 'p')
	{
		ft_putchar('0');
		data->i += 1;
	}
}

void	print_sharp(t_data_pf *data, int j)
{
	if ((data->precision == 0 && data->spe == 'o')
			|| (data->spe == 'o' && j != 0))
		ft_putchar('0');
	else if (data->spe == 'x' && j != 0)
		ft_putstr("0x");
	else if (data->spe == 'X' && j != 0)
		ft_putstr("0X");
}
