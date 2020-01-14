/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:36:34 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/04 23:58:20 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_field(t_data_pf *data)
{
	data->field = ft_atoi(data->format + data->j);
	while (ft_isdigit(data->format[data->j]) == 1)
		data->j += 1;
}
