/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:15:14 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/27 07:58:56 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../srcs/libft/libft.h"

/*
** STRUCTURES
*/

typedef struct			s_links
{
	char				*name;
	int					hash;
	struct s_room		*room;
	struct s_links		*next;
	int					flux;
}						t_links;

typedef struct			s_room
{
	char				*name;
	int					coord_x;
	int					coord_y;
	struct s_links		*links;
	struct s_room		*next;
	struct s_room		*previous;
	int					pass;
}						t_room;

typedef struct			s_path
{
	struct s_room		*room;
	struct s_path		*previous;
	struct s_path		*next;
}						t_path;

typedef struct			s_data
{
	struct s_room		*hashtable[8111];
	int					ants;
	int					ant_regis;
	int					nb_path;
	struct s_room		*start;
	struct s_room		*end;
	struct s_path		*last;
	struct s_best		*best;
	struct s_best		*challenger;
	int					pass;
	char				*line;
}						t_data;

typedef struct			s_ants_info
{
	struct s_room		*room;
	struct s_ants_info	*next_start;
	struct s_ants_info	*next;
	int					moves;
	int					nb_ants;
	int					ants_in;
	int					ants_out;
}						t_ants_info;

typedef struct			s_best
{
	int					total_moves;
	int					nb_steps;
	struct s_ants_info	*infos;
	int					nb_path;
}						t_best;

/*
**	LM_GETPATH_C
*/

int						lm_path_lenght(t_room *current_room, t_data *data);
void					lm_nb_path(t_data *data);
void					lm_total_path_lenght(t_data *data);

/*
**	LM_GETROOM_C
*/

int						lm_get_room(t_data *data, char **line);
int						hachage(char *name, size_t l);
char					**lm_check_room(t_data *data, char **line);

/*
** LM_GETMAPS_C
*/

void					lm_getstart(t_data *data, char **line);
void					lm_getend(t_data *data, char **line);
t_room					*lm_fillroom(t_data *data, char **room, char **line, int hash);

/*
** LM_BFS_C
*/

int						lm_add_links(t_path *current_path, t_path **last, t_data *data);
int						lm_bfs(t_data *data);
void					lm_edmonds_karp(t_data *data);

/*
** LM_FLUX_C
*/

int						lm_get_flux(t_path *current_path);
t_links					*lm_flux_dependance(t_links *current_link, int a, int b);
int						lm_flux_gestion(t_links *current_link, t_data *data, t_path **last,
						t_path *current_path);

/*
** LM_GETPIPES
*/

void					lm_pipe(t_data *data, char **line);
int						lm_get_pipe(t_data *data, char **line);
int						lm_link_room(t_room *room_0, t_room *room_1);

/*
**	LM_COMPARE_H
*/

void					lm_get_line(t_data *data, char **line);
void					lm_compare(t_data *data);

/*
**	LM_FREE_C
*/

void					lm_exit(t_data *data, char *print);
void					lm_free_exit(t_data *data, char **line);
void					lm_free_str(char **str);

/*
**	LM_PRINT_ROOM_C
*/

void					lm_print_rooms(t_data *data);
void					lm_print_path(t_path *path);
void					lm_print_best(t_best *best);

/*
** LM_OUTPUT_C
*/

void					lm_output(t_data *data);

#endif
