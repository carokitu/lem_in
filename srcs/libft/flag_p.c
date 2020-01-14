/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 05:37:34 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/04 23:58:29 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list			*flag_p(va_list ap, t_data_pf *data)
{
	uintptr_t	adress;

	data->precision = 0;
	data->spe = 'p';
	adress = (uintptr_t)(va_arg(ap, void*));
	data->field -= 2;
	print_unsigned(adress, "0123456789abcdef", data);
	return (0);
}
