/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:36:07 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/22 19:11:59 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lm_nb_ants(t_data *data, char **line)
{
	while (get_next_line(0, line) == 1)
	{
		if (!(*line[0] == '#' && (!(*line[1]) || (!(*line[1] != '#' )))))
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
	{
		ft_printf("ERROR_2\n");
		free(line);
		free(data);
		exit(EXIT_FAILURE);
	}
	free(*line);
}

static void		lm_checkorders(t_data *data, char **line)
{
	if (ft_strcmp(*line, "##start\n") == 0)
		lm_getstart(data, line);
	else if (ft_strcmp(*line, "##end\n") == 0)
		lm_getend(data, line);
	else
	{
/*		free(line);
		if (data->start)
			free(data->start);
		if(data->end)
			free(data->end);
		free(data);
		//FREE HASHTABLE ?
		ft_printf("ERROR_4");
		exit(EXIT_FAILURE);*/
	// toute commande inconnue sera ignoree
		return ;
	}
}

static void		lm_room(t_data *data, char **line)
{
	while (get_next_line(0, line) == 1)
	{
		if (!(*line[0] == '#'))
		{
			if (lm_get_room(data, line) == -1)
			//	lm_free_exit(data, line);
				return;
		}
		if ((*line)[0] == '#' && (*line)[1] && (*line)[1] == '#')
			lm_checkorders(data, line);
	}
}

static void		lm_nb_path(t_data *data)
{
	int		i;
	t_links	*link;

	i = 0;
	link = data->start->links;
	while (link)
	{
		if (link->flux == 1)
			i++;
		link = link->next;
	}
	data->challenger->nb_path = i;
	ft_printf("nb path = %d\n", data->challenger->nb_path);
}


static int		lm_path_lenght(t_room *current_room, t_data *data)
{
	int 		i;
	t_links		*count_links;
	t_ants_info	*start;
	t_ants_info	*current;
	t_ants_info	*next;

	i = 1;
	if (data->challenger)
		start = data->challenger->infos;
	else
		//free tout
		exit(EXIT_SUCCESS);
	while (start->next_start)
		start = start->next_start;
	current = start;
	while (current_room != data->end)
	{	
		count_links = current_room->links;
		while (count_links && count_links->flux != 1)
			count_links = count_links->next;
		i++;
		current_room = count_links->room;
		count_links = current_room->links;
		if (!(next = (t_ants_info *)ft_memalloc(sizeof(t_ants_info))))
			//free tout
			exit(EXIT_SUCCESS);
		next->room = current_room;
		current->next = next;
		current = current->next;
	}
	start->moves = i;
	return (i);
}

static void		lm_total_path_lenght(t_data *data)
{
	int				i;
	t_room			*current_room;
	t_links			*current_link;
	t_ants_info		*current_start;
	t_ants_info		*next_start;

	i = 0;
	current_room = data->start;
	current_link = current_room->links;
	while (current_link)
	{
		if (current_link->flux == 1)
		{
			current_room = current_link->room;
			if (data->challenger == NULL)
			{
				if ((!(data->challenger = (t_best *)ft_memalloc(sizeof(t_best))))
				|| !(current_start = (t_ants_info *)ft_memalloc(sizeof(t_ants_info))))
				{
					// free tout
					exit(EXIT_SUCCESS);
				}
				current_start->room = current_room;
				data->challenger->infos = current_start;
			}
			else
			{
				if (!(next_start = (t_ants_info *)ft_memalloc(sizeof(t_ants_info))))
					//free tout
					exit(EXIT_FAILURE);
				next_start->room = current_room;
				current_start->next_start = next_start;
				current_start = current_start->next_start;
			}
			i += lm_path_lenght(current_room, data);
		}
		current_link = current_link->next;
		
	}
	data->challenger->total_moves = i;
	//ft_printf("ICI ON PEUT VOIR ? %d\n", i);
}

void			lm_total_moves(t_data *data)
{
	float			moves;
	t_ants_info	*ants_info;

	ants_info = data->challenger->infos;
	while (ants_info)
	{
		moves = ((((float)data->ants + (float)data->challenger->total_moves) /
				(float)data->challenger->nb_path)) - (float)ants_info->moves;
		ants_info->nb_ants = (int)moves;
		if (moves > (float)ants_info->nb_ants)
			ants_info->nb_ants++;// FAIRE ATTENTION ON PEUT AVOIR TROP DE FOURMIS
		if (ants_info->nb_ants + ants_info->moves - 1 > data->challenger->nb_steps)
			data->challenger->nb_steps = ants_info->nb_ants + ants_info->moves - 1;
		//ft_printf("ants_info->nb_ants = %d\n", (int)moves);
		ants_info = ants_info->next_start;
	}
}

static void		lm_parsing(t_data *data)
{
	char	*line;

	line = NULL;
	lm_nb_ants(data, &line);
	lm_room(data, &line);
	lm_pipe(data, &line);
	ft_printf("*---------------------------*\n");
	while (lm_bfs(data) == 1)
	{
		//lm_print_path(data->last);
		lm_total_path_lenght(data);
		lm_nb_path(data);
		//lm_print_best(data->challenger);
		lm_total_moves(data);
		lm_compare(data);
		// comparer best et challenger
		// data->challenger = NULL
//		free(data->challenger);
//		data->challenger = NULL;
	}
	lm_print_best(data->best);
	lm_output(data);
	//lm_print_best(data->best);
}

int			main(int argc, char **argv)
{
	t_data	*data;

	//pas sure du argv = NULL
	argv = NULL;
	if (argc != 1)
	{
		ft_printf("ERROR_3\n");
		return (1);
	}
	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		exit(EXIT_FAILURE);
	lm_parsing(data);
}
