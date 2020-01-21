/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:36:07 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/21 17:28:14 by cde-moul         ###   ########.fr       */
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
	data->nb_path = i;
	ft_printf("nb path = %d\n", data->nb_path);
}


static int		lm_path_lenght(t_room *current_room, t_data *data)
{
	int 		i;
	t_links		*count_links;

	i = 1;
	while (current_room != data->end)
	{	
		count_links = current_room->links;
		while (count_links && count_links->flux != 1)
			count_links = count_links->next;
		i++;
		current_room = count_links->room;
		count_links = current_room->links;
	}
	ft_printf("path lenght i = %d\n", i);
	return (i);
}

static void		lm_total_path_lenght(t_data *data)
{
	int				i;
	t_room			*current_room;
	t_links			*current_link;
	t_ants_infos	*starts;
	t_ants_infos	*next_start;

	i = 0;
	if (!(data->challenger = (t_best *)ft_memalloc(sizeof(t_best))) 
	|| !(starts = (t_ants_infos *)ft_memalloc(sizeof(t_ants_infos)))
	|| !(next_start = (t_ants_infos *)ft_memalloc(sizeof(t_ants_infos))))
	{
		//free all
		exit(EXIT_FAILURE)
	}
	current_room = data->start;
	current_link = current_room->links;
	while (current_link)
	{
		if (current_link->flux == 1)
		{
			current_room = current_link->room;
			if (starts != NULL)
				starts->room = current_link->name;
			else
			{
				next_start->room = current_link->name;
				next_start->next_start = starts;
			}
			// envoyer start
			i += lm_path_lenght(current_room, data);
		}
		current_link = current_link->next;
		
	}
	ft_printf("ICI ON PEUT VOIR ? %d\n", i);
}

static void		lm_parsing(t_data *data)
{
	char	*line;

	line = NULL;
	lm_nb_ants(data, &line);
	lm_room(data, &line);
	lm_pipe(data, &line);
	ft_printf("*---------------------------*\n");
//	while ("pas de chemin possible")
	while (lm_bfs(data) == 1)
	{
		lm_print_path(data->last);
		lm_nb_path(data);
		lm_total_path_lenght(data);
	}
	//lancer test_coups puis mettre dans best ou non
	//lancer officiel des fourmis dans le best
//	lm_free_exit(data, &line);
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
