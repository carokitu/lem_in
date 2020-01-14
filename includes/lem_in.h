/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:15:14 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/14 17:24:32 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "srcs/lib/libft.h"

/*
** STRUCTURES
*/

typedef struct s_links
{
	char		*name;
	int			hash;
	t_links		*next;
}				t_links;

typedef struct s_room
{
	char		*name;
	int			coord_x;
	int			coord_y;
	s_links		*links;
	t_room		*next;
}				t_room;

typedef struct	s_data
{
	t_room		*hashtable[8111];
	int			ants;
	int			order;
	s_room		*start;
	s_room		*end;
}				t_data;

/*
** LM_GETMAPS_C
*/

char    **lm_check_room(t_data *data, char **line);
int     hachage(char *name, size_t l);
void    lm_getstart(t_data *data, char **line);
void    lm_getend(t_data *data, char **line);
void    lm_get_room(t_data *data, char **line);


#endif
