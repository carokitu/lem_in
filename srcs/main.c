/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:36:07 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/27 08:30:34 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void				lm_nb_ants(t_data *data, char **line)
{
	while (get_next_line(0, line) == 1)
	{
		lm_get_line(data, line);
		if (!(*line[0] == '#' && (!(*line[1]) || (!(*line[1] != '#')))))
		{
			if (ft_isanint(*line) == 1)
			{
				data->ants = ft_atoi(*line);
				break ;
			}
			else
				lm_free_exit(data, line);
			free(*line);
		}
	}
	if (data->ants <= 0)
		lm_free_exit(data, line);
	free(*line);
}

static void				lm_room(t_data *data, char **line)
{
	while (get_next_line(0, line) == 1)
	{
		lm_get_line(data, line);
		if (!(*line[0] == '#'))
		{
			if (lm_get_room(data, line) == -1)
			{
			//	free(*line);
				return;
			}
		}
		if ((*line)[0] == '#' && (*line)[1] && (*line)[1] == '#')
		{
			if (ft_strcmp(*line, "##start\n") == 0)
				lm_getstart(data, line);
			else if (ft_strcmp(*line, "##end\n") == 0)
				lm_getend(data, line);

			//Si rien on free pas line autant toujours free line ici;
		}
	}
}

void					lm_total_moves(t_data *data)
{
	float			moves;
	t_ants_info		*ants_info;

	ants_info = data->challenger->infos;
	while (ants_info)
	{
		moves = ((((float)data->ants + (float)data->challenger->total_moves) /
				(float)data->challenger->nb_path)) - (float)ants_info->moves;
		ants_info->nb_ants = (int)moves;
		if (moves > (float)ants_info->nb_ants)
			ants_info->nb_ants++;
// FAIRE ATTENTION ON PEUT AVOIR TROP DE FOURMIS
		if (ants_info->nb_ants + ants_info->moves - 1
			> data->challenger->nb_steps)
			data->challenger->nb_steps =
				ants_info->nb_ants + ants_info->moves - 1;
		ants_info = ants_info->next_start;
	}
}

static void				lm_parsing(t_data *data)
{
	char	*line;

	line = NULL;
	lm_nb_ants(data, &line);
	lm_room(data, &line);
	lm_pipe(data, &line);
	// ca devrait pas etre dans la fonction de parsing
	while (lm_bfs(data) == 1)
	{
		lm_total_path_lenght(data);
		lm_nb_path(data);
		lm_total_moves(data);
		lm_compare(data);
	}
//	lm_print_best(data->best);
	lm_output(data);
}

int						main(int argc, char **argv)
{
	t_data	*data;

	argv = NULL;
	if (argc != 1)
	{
// changer message erreur
		ft_printf("ERROR_3\n");
		return (1);
	}
	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		exit(EXIT_FAILURE);
	lm_parsing(data);
}
