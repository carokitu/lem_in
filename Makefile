# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/18 13:45:49 by cde-moul          #+#    #+#              #
#    Updated: 2020/01/15 18:18:42 by cde-moul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC			=	lem-in

SRCSDIR			=	./srcs

OBJSDIR			=	./objs

SRCSLIB			=	./srcs/libft

INCLUDES		=	./includes/lem_in.h

SRCS			=	main.c \
					lm_getmaps.c \
					lm_getpipes.c \
					lm_bfs.c

OBJS			=	$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

CC				=	gcc -g

CFLAGS			=	-Wall -Wextra -Werror

INCL			=	-I includes/

RM				=	rm -f

all				:	libft $(EXEC)

$(EXEC)			:	$(OBJS) $(OBJLIB) $(INCLUDES)
					$(CC) $(CFLAGS) $(INCL) $(OBJS) -o $(EXEC) ./srcs/libft/libft.a

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c $(INCLUDES)
					@mkdir -p $(OBJSDIR) 2> /dev/null || true
					$(CC) -c $(CFLAGS) $(INCL) -c $< -o $@

libft			:
#   make -C srcs/libft/
					@(cd $(SRCSLIB) && $(MAKE)) 


clean			:
					rm -rf $(OBJSDIR)

fclean			:	clean
					$(RM) $(EXEC)

re				:
					make fclean
					make all

.PHONY			:	clean fclean re libft