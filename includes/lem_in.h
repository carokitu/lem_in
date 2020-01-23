/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:15:14 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/23 10:51:42 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../srcs/libft/libft.h"

/*
** STRUCTURES
*/

typedef struct 		s_links
{
	char			*name;
	int				hash;
	struct s_room	*room;
	struct s_links	*next;
	int				flux;
}					t_links;

typedef struct s_room
{
	char		*name;
	int			coord_x;
	int			coord_y;
	struct s_links		*links;
	struct s_room		*next;
	struct s_room		*previous;
	int			pass;
}				t_room;

typedef struct	s_path
{
	struct s_room		*room;
	struct s_path		*previous;
	struct s_path		*next;
}				t_path;

typedef struct	s_data
{
	struct s_room			*hashtable[8111];
	int						ants;
	int						ant_regis;;
	int						nb_path;
	struct	s_room			*start;
	struct	s_room			*end;
	struct	s_path			*last;
	struct	s_best			*best;
	struct	s_best			*challenger;
	int			pass;
	char					*line;	
}							t_data;

typedef struct	s_ants_info
{
	t_room				*room;
	struct s_ants_info	*next_start;
	struct s_ants_info	*next;
	int					moves;
	int					nb_ants;
	int					ants_in;
	int					ants_out;
}				t_ants_info;

typedef struct		s_best
{
	int				total_moves;
	int				nb_steps;
	t_ants_info		*infos;
	int				nb_path;
}					t_best;

/*
** LM_GETMAPS_C
*/

char	**lm_check_room(t_data *data, char **line);
int		hachage(char *name, size_t l);
void	lm_getstart(t_data *data, char **line);
void	lm_getend(t_data *data, char **line);
int		lm_get_room(t_data *data, char **line);

/*
** LM_BFS_S
*/

int		lm_add_links(t_path *current_path, t_path **last, t_data *data);
int		lm_bfs(t_data *data);

/*
** LM_GETPIPES
*/

void	lm_pipe(t_data *data, char **line);
int		lm_get_pipe(t_data *data, char **line);
int		lm_link_room(t_room *room_0, t_room *room_1);

/*
**	LM_COMPARE_H
*/

void	lm_compare(t_data *data);

/*
**	LM_FREE_C
*/

void	lm_free_exit(t_data *data, char **line);
void	lm_free_str(char **str);

/*
**	LM_PRINT_ROOM_C
*/

void	lm_print_rooms(t_data *data);
void	lm_print_path(t_path *path);
void	lm_print_best(t_best *best);

/*
** LM_OUTPUT_C
*/

void	lm_output(t_data *data);

#endif

