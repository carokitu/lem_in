/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percentage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:00:27 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/04 23:59:06 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put(t_data_pf *data)
{
	ft_putchar(data->format[data->j++]);
	data->i++;
}

void	print_percentage(t_data_pf *data)
{
	while (data->field > 1 && data->minus == 0 && data->zero == 0)
	{
		ft_putchar(' ');
		data->field -= 1;
		data->i += 1;
	}
	while (data->field > 1 && data->minus == 0 && data->zero == 1)
	{
		ft_putchar('0');
		data->field -= 1;
		data->i += 1;
	}
	ft_putchar('%');
	while (data->field > 1 && data->minus == 1)
	{
		ft_putchar(' ');
		data->field -= 1;
		data->i += 1;
	}
	data->j += 1;
	data->i += 1;
}
