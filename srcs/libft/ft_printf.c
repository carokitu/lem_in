/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:37:53 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/05 00:10:58 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_func	g_tab[] =
{
	{&flag_di, 'd'},
	{&flag_di, 'i'},
	{&flag_s, 's'},
	{&flag_c, 'c'},
	{&flag_u, 'u'},
	{&flag_o, 'o'},
	{&flag_x, 'x'},
	{&flag_xx, 'X'},
	{&flag_p, 'p'},
	{&flag_f, 'f'},
	{NULL, -1}
};

t_flag	g_flag[] =
{
	{&flag_sharp, '#'},
	{&flag_plus, '+'},
	{&flag_minus, '-'},
	{&flag_zero, '0'},
	{&flag_space, ' '},
	{&flag_precision, '.'},
	{&flag_field, '1'},
	{&flag_field, '2'},
	{&flag_field, '3'},
	{&flag_field, '4'},
	{&flag_field, '5'},
	{&flag_field, '6'},
	{&flag_field, '7'},
	{&flag_field, '8'},
	{&flag_field, '9'},
	{&flag_h, 'h'},
	{&flag_l, 'l'},
	{&flag_long_double, 'L'},
	{NULL, -1}
};

void	exec_specifier(char c, va_list ap, t_data_pf *data)
{
	int			i;

	i = 0;
	while (g_tab[i].key != -1)
	{
		if (g_tab[i].key == c)
			g_tab[i].ptrfunc(ap, data);
		i++;
	}
}

void	exec_flag(char c, t_data_pf *data)
{
	int			i;

	i = 0;
	while (g_flag[i].key != -1)
	{
		if (g_flag[i].key == c)
			g_flag[i].ptrfunc(data);
		i++;
	}
}

void	ft_init_data_pf(t_data_pf *data, const char **format)
{
	data->format = *format;
	data->i = 0;
	data->j = 0;
	data->casth = 0;
	data->castl = 0;
	data->zero = 0;
	data->field = 0;
	data->precision = -1;
	data->plus = 0;
	data->sharp = 0;
	data->zero = 0;
	data->space = 0;
	data->minus = 0;
	data->neg = 1;
	data->digits = 0;
	data->pass = 0;
	data->add_one = 0;
	data->long_double = 0;
	data->spe = '|';
}

void	ft_reset_flag(t_data_pf *data)
{
	data->casth = 0;
	data->castl = 0;
	data->zero = 0;
	data->field = 0;
	data->precision = -1;
	data->sharp = 0;
	data->minus = 0;
	data->plus = 0;
	data->space = 0;
	data->neg = 1;
	data->digits = 0;
	data->pass = 0;
	data->add_one = 0;
	data->long_double = 0;
	data->spe = '|';
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_data_pf	data;

	ft_init_data_pf(&data, &format);
	va_start(ap, format);
	while (format[data.j] != '\0')
	{
		while (format[data.j] == '%')
		{
			data.j++;
			while (list_flag(format[data.j]) == 1)
				exec_flag(format[data.j], &data);
			if (format[data.j] && format[data.j] == '%')
				print_percentage(&data);
			else if (format[data.j] && format[data.j] != '%')
				exec_specifier(format[data.j++], ap, &data);
			ft_reset_flag(&data);
		}
		if (format[data.j] != '\0')
			ft_put(&data);
	}
	va_end(ap);
	return (data.i);
}
