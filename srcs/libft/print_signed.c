/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:52:33 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/04 23:59:23 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	neg_care(long long nb, t_data_pf *data)
{
	data->neg = 1;
	if (nb < 0)
	{
		if (nb % 10 != 0 && (nb > 10 || nb < -10))
		{
			data->add_one = 1;
			nb += 1;
		}
		nb = nb * -1;
		data->neg = -1;
	}
	return (nb);
}

void		print_signed(long long nb, char *base, t_data_pf *data)
{
	int		tab[100];
	char	tab2[100];
	int		b;
	int		j;
	int		i;

	j = 0;
	i = 0;
	nb = neg_care(nb, data);
	b = check_nb(data, nb, base);
	while (nb != 0)
	{
		tab[j++] = nb % b;
		nb = nb / b;
	}
	data->add_one == 1 ? tab[0] += 1 : 0;
	data->digits = (nb == 0 && data->precision == 0) ? j : data->digits;
	print_fill(data);
	print_prec(data);
	while (--j >= 0)
		tab2[i++] = base[tab[j]];
	if (!(tab2[i] = '\0') && data->neg == 0)
		ft_putchar('0');
	ft_putstr(tab2);
	print_min(data);
}
