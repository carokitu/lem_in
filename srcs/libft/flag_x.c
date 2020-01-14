/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 09:22:55 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/04 23:58:35 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list	*flag_x(va_list ap, t_data_pf *data)
{
	data->spe = 'x';
	if (data->casth != 0)
	{
		if (data->casth == 1)
			print_unsigned((unsigned short)va_arg(ap, unsigned int),
					"0123456789abcdef", data);
		if (data->casth == 2)
			print_unsigned((unsigned char)va_arg(ap, unsigned int),
					"0123456789abcdef", data);
		return (0);
	}
	if (data->castl != 0)
	{
		if (data->castl == 1)
			print_unsigned((unsigned long)va_arg(ap, unsigned long),
					"0123456789abcdef", data);
		if (data->castl == 2)
			print_unsigned((unsigned long long)va_arg(ap, unsigned long long),
			"0123456789abcdef", data);
		return (0);
	}
	print_unsigned(va_arg(ap, unsigned int), "0123456789abcdef", data);
	return (0);
}

va_list	*flag_xx(va_list ap, t_data_pf *data)
{
	data->spe = 'X';
	if (data->casth != 0)
	{
		if (data->casth == 1)
			print_unsigned((unsigned short)va_arg(ap, unsigned long long),
					"0123456789ABCDEF", data);
		if (data->casth == 2)
			print_unsigned((unsigned char)va_arg(ap, unsigned long long),
					"0123456789ABCDEF", data);
		return (0);
	}
	if (data->castl != 0)
	{
		if (data->castl == 1)
			print_unsigned((unsigned long)va_arg(ap, unsigned long),
					"0123456789ABCDEF", data);
		if (data->castl == 2)
			print_unsigned((unsigned long long)va_arg(ap, unsigned long long),
					"0123456789ABCDEF", data);
		return (0);
	}
	print_unsigned(va_arg(ap, unsigned int), "0123456789ABCDEF", data);
	return (0);
}
