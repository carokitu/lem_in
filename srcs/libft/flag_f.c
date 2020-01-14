/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:02:28 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/04 23:58:13 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_fil(t_data_pf *data)
{
	if (data->space == 1 && data->neg != -1)
	{
		ft_putchar(' ');
		data->field -= 1;
		data->i += 1;
	}
	while (data->field > data->field_2 && data->minus == 0 && data->zero == 0)
	{
		ft_putchar(' ');
		data->field -= 1;
		data->i += 1;
	}
	while (data->field > data->field_2 && data->minus == 0 && data->zero == 1)
	{
		ft_putchar('0');
		data->field -= 1;
		data->i += 1;
	}
	if (data->neg == -1)
		ft_putchar('-');
	if (data->neg != 1 && data->plus == 1)
		ft_putchar('+');
}

long double		correct_flags(long double n, t_data_pf *data)
{
	data->spe = 'f';
	if (data->plus == 1)
		data->space = 0;
	if (data->minus == 1)
		data->zero = 0;
	if (data->precision == -1)
		data->precision = 6;
	if (n < 0)
	{
		n = -n;
		data->neg = -1;
	}
	if (n == 0)
		data->neg = 0;
	data->digits = ft_exponent((unsigned long long)n);
	if (data->precision == 0 && data->sharp == 0)
		data->field_2 = data->digits;
	if (data->precision > 0 || data->sharp == 1)
		data->field_2 = data->precision + data->digits + 1;
	if (data->neg == -1 || data->plus == 1)
		data->field_2 += 1;
	data->i += data->field_2;
	return (n);
}

void			reverse(char *p, char *q)
{
	char		c;

	while (p < q)
	{
		c = *p;
		*p = *q;
		*q = c;
		q--;
		p++;
	}
}

char			*incr(char *s, char *f)
{
	int			co;
	char		*t;

	co = 1;
	t = f;
	while (t >= s && co == 1)
	{
		if (*t == '.')
		{
			t--;
			continue;
		}
		*t += co;
		if (*t > '9')
			*t = '0';
		else
			co = 0;
		t--;
	}
	return (f);
}

va_list			*flag_f(va_list ap, t_data_pf *data)
{
	long double	n;
	char		*save;
	char		*p;
	char		*s;

	if (data->long_double == 0)
		n = va_arg(ap, double);
	else
		n = va_arg(ap, long double);
	n = correct_flags(n, data);
	print_fil(data);
	if (!(save = (char *)malloc(sizeof(save) * (data->field_2 + 1))))
		return (NULL);
	p = save;
	s = save;
	p = ftoa_integer(n, data, p);
	if (data->precision != 0 || data->sharp == 1)
		p = ftoa_decimal(n, data, p, s);
	data->pass == 0 ? incr_integer(n, p, s) : 0;
	*p = '\0';
	ft_putstr(save);
	minus_f(data);
	free(save);
	return (0);
}
