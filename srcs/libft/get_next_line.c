/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:35:06 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/05 19:55:11 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_addline(char **line, char *src, char c)
{
	int				i;
	char			*tmp;
	char			*tmp2;

	i = 0;
	tmp = NULL;
	i = ft_countchar(src, c);
	if (!(tmp = malloc(sizeof(tmp) * (i + 1))))
		return (0);
	tmp = ft_strcpc_include_c(tmp, src, c);
	*line = tmp;
	if (src[i] == '\n')
	{
		if (!(tmp2 = ft_strdup(src + (i + 1))))
			return (NULL);
	}
	else
	{
		if (!(tmp2 = ft_strdup(src + (i))))
			return (NULL);
	}
	free(src);
	return (tmp2);
}

static t_list	*find_save(t_list **save, size_t fd)
{
	t_list			*tmp;

	tmp = *save;
	while (tmp)
	{
		if (tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew("\0", 1)))
		return (NULL);
	tmp->content_size = fd;
	ft_lstadd(save, tmp);
	return (tmp);
}

static int		ft_read(int fd, void **str, t_list *content)
{
	char			buf[BUFF_SIZE + 1];
	int				read_size;
	void			*tmp;

	tmp = NULL;
	while ((read_size = read(fd, buf, BUFF_SIZE)))
	{
		if (read_size == -1)
			return (-1);
		buf[read_size] = '\0';
		tmp = *str;
		if (!(*str = ft_strjoin(*str, buf)))
			return (-1);
		free(tmp);
		tmp = NULL;
		if (ft_memchr(buf, '\n', read_size))
			break ;
	}
	if ((read_size == 0) && !ft_strlen(*str))
	{
		free(content->content);
		free(content);
		return (0);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*save;
	t_list			*current;
	int				ret;

	if (fd < 0 || BUFF_SIZE <= 0 || !line || read(fd, "test", 0))
		return (-2);
	current = find_save(&save, fd);
	*line = NULL;
	ret = ft_read(fd, &(current->content), current);
	if (ret && !(current->content = ft_addline(&(*line),
	current->content, '\n')))
		return (-1);
	return (ret);
}
