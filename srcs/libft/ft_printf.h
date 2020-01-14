/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 02:22:14 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/04 23:59:03 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_data_pf
{
	int				i;
	int				casth;
	int				castl;
	const char		*format;
	int				j;
	int				zero;
	int				plus;
	int				minus;
	int				sharp;
	int				space;
	int				field;
	int				precision;
	int				neg;
	int				pass;
	int				digits;
	char			spe;
	int				field_2;
	int				add_one;
	int				long_double;
}					t_data_pf;

void				flag_h(t_data_pf *data);
void				flag_l(t_data_pf *data);

va_list				*flag_s(va_list ap, t_data_pf *data);
va_list				*flag_di(va_list ap, t_data_pf *data);
va_list				*flag_c(va_list ap, t_data_pf *data);
va_list				*flag_u(va_list ap, t_data_pf *data);
va_list				*flag_o(va_list ap, t_data_pf *data);
va_list				*flag_x(va_list ap, t_data_pf *data);
va_list				*flag_xx(va_list ap, t_data_pf *data);
va_list				*flag_p(va_list ap, t_data_pf *data);
va_list				*flag_f(va_list ap, t_data_pf *data);

void				print_pointer(t_data_pf *data, int j);
void				print_sharp(t_data_pf *data, int j);
void				print_field_2(t_data_pf *data, int j);

void				exec_specifier(char c, va_list ap, t_data_pf *data);
void				exec_flag(char c, t_data_pf *data);

void				print_percentage(t_data_pf *data);

typedef struct		s_func
{
	va_list			*(*ptrfunc)(va_list ap, t_data_pf *data);
	char			key;
}					t_func;

typedef struct		s_flag
{
	void			(*ptrfunc)(t_data_pf *data);
	char			key;
}					t_flag;

void				print_signed(long long nb, char *bas, t_data_pf *data);
void				print_unsigned(unsigned long long nb,
		char *base, t_data_pf *data);
void				print_str(char *s, t_data_pf *data);

int					list_flag(char c);
void				flag_sharp(t_data_pf *data);
void				flag_zero(t_data_pf *data);
void				flag_space(t_data_pf *data);
void				flag_plus(t_data_pf *data);
void				flag_minus(t_data_pf *data);
void				flag_field(t_data_pf *data);
void				flag_precision(t_data_pf *data);
int					ft_printf(const char *format, ...);

int					check_nb(t_data_pf *data, long long nb, char *base);
void				print_fill(t_data_pf *data);
void				ft_sign(t_data_pf *data);
void				print_prec(t_data_pf *data);
void				print_min(t_data_pf *data);
void				ft_putstr(char const *str);
void				print_sharp(t_data_pf *data, int j);
void				flag_long_double(t_data_pf *data);
int					list_specifier(char c);
void				incr_integer(long double n, char *dest, char *s);
void				minus_f(t_data_pf *data);
int					ft_exponent(unsigned long long n);
char				*ftoa_decimal(long double n, t_data_pf *data, char *dest,
					char *s);
char				*ftoa_integer(long double n, t_data_pf *data, char *dest);
char				*incr(char *s, char *f);
void				reverse(char *p, char *q);
void				ft_put(t_data_pf *data);

#endif
