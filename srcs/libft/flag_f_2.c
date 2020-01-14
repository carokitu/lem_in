/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:15:44 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/05 00:11:41 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			minus_f(t_data_pf *data)
{
	while (data->field_2 < data->field)
	{
		ft_putchar(' ');
		data->i++;
		data->field_2++;
	}
}

void			incr_integer(long double n, char *dest, char *s)
{
	long double decimal;

	decimal = n - (long long)n;
	decimal *= 10;
	if ((int)decimal >= 5)
		dest = incr(s, dest - 1) + 1;
}

int				ft_exponent(unsigned long long n)
{
	int			i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ftoa_decimal(long double n, t_data_pf *data,
				char *dest, char *s)
{
	int			precision;
	long double	decimal;

	decimal = n - (long long)n;
	precision = data->precision;
	*dest++ = '.';
	while (precision)
	{
		decimal *= 10;
		*dest++ = '0' + (int)decimal;
		decimal -= (int)decimal;
		precision--;
	}
	decimal *= 10;
	if ((int)decimal >= 5)
		dest = incr(s, dest - 1) + 1;
	data->pass = 1;
	return (dest);
}

char			*ftoa_integer(long double n, t_data_pf *data, char *dest)
{
	long long	integer;
	int			i;
	char		*p;

	p = dest;
	i = 0;
	integer = (long long)n;
	if (integer)
	{
		while (integer && i++ <= data->digits)
		{
			*p++ = ('0' + (integer % 10));
			integer /= 10;
		}
		reverse(dest, p - 1);
	}
	else
	{
		*dest++ = '0';
		p++;
	}
	return (p);
}
