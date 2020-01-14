/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_base_v2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:15:07 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/04 23:59:08 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_nb(t_data_pf *data, long long nb, char *base)
{
	int		b;
	int		j;

	j = 1;
	if (nb == 0)
		data->neg = 0;
	if (nb == 0 && data->precision == 0)
		data->neg = 2;
	b = ft_strlen(base);
	data->digits = ft_countdigits_base(nb, b);
	if (data->minus == 1)
		data->zero = 0;
	return (b);
}

void		print_fill(t_data_pf *data)
{
	if (data->precision != 0 || data->neg != 2)
		data->i += data->digits;
	if (data->precision != -1)
		data->zero = 0;
	if (data->precision < data->digits)
		data->precision = data->digits;
	data->field -= data->precision;
	if (data->zero == 1 && data->minus == 0)
		ft_sign(data);
	while (data->field > 1 && data->minus == 0)
	{
		if (data->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		data->field -= 1;
		data->i += 1;
	}
	if (data->field == 1 && data->zero == 1)
	{
		ft_putchar('0');
		data->field -= 1;
		data->i += 1;
	}
}

void		ft_sign(t_data_pf *data)
{
	data->i += 1;
	data->field -= 1;
	if (data->neg == -1)
		ft_putchar('-');
	else if (data->plus == 1 && data->neg >= 0)
		ft_putchar('+');
	else if (data->space == 1 || (data->field == 0 && data->minus == 0))
		ft_putchar(' ');
	else if (data->zero == 1 && data->field > -1)
		ft_putchar('0');
	else
	{
		data->field += 1;
		data->i -= 1;
	}
	data->pass = 1;
}

void		print_prec(t_data_pf *data)
{
	if (data->pass == 0)
		ft_sign(data);
	while (data->precision > data->digits)
	{
		ft_putchar('0');
		data->i += 1;
		data->precision--;
	}
}

void		print_min(t_data_pf *data)
{
	while (data->field > 0 && data->minus == 1)
	{
		ft_putchar(' ');
		data->field -= 1;
		data->i += 1;
	}
}
