# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:15:16 by fgaribot          #+#    #+#              #
#    Updated: 2019/11/05 17:35:20 by fgaribot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I ./includes
AR = ar rc
SRC = ./
FILES = $(SRC)ft_abs.c\
		$(SRC)ft_memset.c\
		$(SRC)ft_bzero.c\
		$(SRC)ft_memcpy.c\
		$(SRC)ft_memccpy.c\
		$(SRC)ft_memmove.c\
		$(SRC)ft_memchr.c\
		$(SRC)ft_memcmp.c\
		$(SRC)ft_strlen.c\
		$(SRC)ft_strdup.c\
		$(SRC)ft_strcpy.c\
		$(SRC)ft_strncpy.c\
		$(SRC)ft_strcat.c\
		$(SRC)ft_strlcat.c\
		$(SRC)ft_strncat.c\
		$(SRC)ft_strchr.c\
		$(SRC)ft_strrchr.c\
		$(SRC)ft_strstr.c\
		$(SRC)ft_strnstr.c\
		$(SRC)ft_strcmp.c\
		$(SRC)ft_strncmp.c\
		$(SRC)ft_putstr.c\
		$(SRC)ft_putstr_fd.c\
		$(SRC)ft_putchar.c\
		$(SRC)ft_atoi.c\
		$(SRC)ft_putchar_fd.c\
		$(SRC)ft_putnbr.c\
		$(SRC)ft_isanint.c\
		$(SRC)ft_isalpha.c\
		$(SRC)ft_isdigit.c\
		$(SRC)ft_isalnum.c\
		$(SRC)ft_isascii.c\
		$(SRC)ft_isprint.c\
		$(SRC)ft_toupper.c\
		$(SRC)ft_tolower.c\
		$(SRC)ft_memalloc.c\
		$(SRC)ft_memdel.c\
		$(SRC)ft_strnew.c\
		$(SRC)ft_strdel.c\
		$(SRC)ft_strclr.c\
		$(SRC)ft_striter.c\
		$(SRC)ft_striteri.c\
		$(SRC)ft_strmap.c\
		$(SRC)ft_strmapi.c\
		$(SRC)ft_strequ.c\
		$(SRC)ft_strnequ.c\
		$(SRC)ft_strsub.c\
		$(SRC)ft_strjoin.c\
		$(SRC)ft_strtrim.c\
		$(SRC)ft_strsplit.c\
		$(SRC)ft_countsplit.c\
		$(SRC)ft_countchar.c\
		$(SRC)ft_strcpc.c\
		$(SRC)ft_putendl.c\
		$(SRC)ft_putendl_fd.c\
		$(SRC)ft_putnbr_fd.c\
		$(SRC)ft_itoa.c\
		$(SRC)ft_countdigits.c\
		$(SRC)ft_strrev.c\
		$(SRC)ft_lstnew.c\
		$(SRC)ft_lstdelone.c\
		$(SRC)ft_lstdel.c\
		$(SRC)ft_lstadd.c\
		$(SRC)ft_lstiter.c\
		$(SRC)ft_lstmap.c\
		$(SRC)ft_sort_int_tab.c\
		$(SRC)ft_recursive_power.c\
		$(SRC)get_next_line.c\
		$(SRC)ft_strtrimc.c\
		$(SRC)ft_strcpc_include_c.c\
		$(SRC)ft_printf.c\
		$(SRC)decimal_print_base_anex.c\
		$(SRC)decimal_print_base.c\
		$(SRC)flag_c.c\
		$(SRC)flag_di.c\
		$(SRC)flag_f.c\
		$(SRC)flag_f_2.c\
		$(SRC)flag_field.c\
		$(SRC)flag_long_double.c\
		$(SRC)flag_o.c\
		$(SRC)flag_precision.c\
		$(SRC)flag_s.c\
		$(SRC)flag_u.c\
		$(SRC)flag_x.c\
		$(SRC)flag_x.c\
		$(SRC)flags.c\
		$(SRC)print_percentage.c\
		$(SRC)print_signed_base_v2.c\
		$(SRC)print_signed.c\
		$(SRC)flag_p.c\
		$(SRC)flag_h_v2.c\
		$(SRC)flag_l_v2.c\
		$(SRC)ft_countdigits_base.c\
		$(SRC)list_flag.c\
		$(SRC)free_tab.c\
		$(SRC)ft_replace.c

OBJ = $(FILES:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@($(AR) $(NAME) $(OBJ))
	@(ranlib $(NAME))

clean :
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
