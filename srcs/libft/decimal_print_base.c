/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_print_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 09:18:16 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/04 23:57:39 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_base(t_data_pf *data, unsigned long long nb, char *base)
{
	int		b;
	int		j;

	j = 1;
	data->neg = 1;
	if (nb <= 0)
	{
		nb = -nb;
		data->neg = -1;
		if (nb == 0)
			data->neg = 0;
	}
	b = ft_strlen(base);
	data->digits = ft_countdigits_base(nb, b);
	return (b);
}

void		print_field(t_data_pf *data, int j)
{
	if (data->precision != -1)
		data->zero = 0;
	if ((data->precision == 0 && j == 0) && (data->spe == 'o'
	|| data->spe == 'u' || data->spe == 'x' || data->spe == 'X'))
		data->pass = 666;
	if (data->precision < data->digits && data->pass != 666)
		data->precision = data->digits;
	if (data->sharp == 1)
	{
		if ((data->precision == 0 && data->spe == 'o')
		|| (data->spe == 'o' && j != 0))
		{
			if (data->precision != data->digits && data->pass != 666)
				data->precision -= 1;
			data->i += 1;
			data->field -= 1;
		}
		else if ((data->spe == 'x' || data->spe == 'X') && j != 0)
		{
			data->i += 2;
			data->field -= 2;
		}
	}
	data->field -= data->precision;
	print_field_2(data, j);
}

void		print_field_2(t_data_pf *data, int j)
{
	while (data->field > 0 && data->minus == 0 && data->zero == 0)
	{
		ft_putchar(' ');
		data->field -= 1;
		data->i += 1;
	}
	if (data->sharp == 1)
		print_sharp(data, j);
	while (data->field > 0 && data->minus == 0 && data->zero == 1)
	{
		ft_putchar('0');
		data->field -= 1;
		data->i += 1;
	}
	while (data->precision > data->digits)
	{
		ft_putchar('0');
		data->i += 1;
		data->precision--;
	}
	if (data->neg == 0 && data->precision != 0 && data->spe != 'p')
	{
		ft_putchar('0');
		data->i += 1;
	}
}

void		print_minus(t_data_pf *data)
{
	while (data->field > 0 && data->minus == 1)
	{
		ft_putchar(' ');
		data->field -= 1;
		data->i += 1;
	}
}

void		print_unsigned(unsigned long long nb, char *base, t_data_pf *data)
{
	int		tab[100];
	char	tab2[100];
	int		b;
	int		j;
	int		i;

	j = 0;
	i = 0;
	b = get_base(data, nb, base);
	while (nb != 0)
	{
		tab[j++] = nb % b;
		nb = nb / b;
		data->digits = j;
	}
	if (j != 0)
		data->i += data->digits;
	print_field(data, j);
	print_pointer(data, j);
	while (--j >= 0)
		tab2[i++] = base[tab[j]];
	tab2[i] = '\0';
	ft_putstr(tab2);
	print_minus(data);
}
