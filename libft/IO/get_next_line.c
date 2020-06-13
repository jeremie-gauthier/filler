/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:00:06 by jergauth          #+#    #+#             */
/*   Updated: 2018/11/21 15:41:26 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	-->	Get_file
**	Manage the linked list.
**	Browse the list, searching for the fd if it exists. Or creating the node
**	at the beginning of the list.
*/

static t_file	*get_file(const int fd, t_file **list)
{
	t_file	*new;
	t_file	*current;

	current = *list;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	if (!(new = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	new->fd = fd;
	new->str = NULL;
	new->next = *list;
	*list = new;
	return (new);
}

/*
**	--> fill_line
**	Fill the 'line' pointer with a line.
**	(line = chars delimited by '\n' or '\0').
*/

static int		fill_line(t_file *list, char **line)
{
	char	*newline;
	char	*tmp;

	if ((newline = ft_strchr(list->str, '\n')))
	{
		tmp = list->str;
		if (!(*line = ft_strsub(list->str, 0, newline - list->str)))
			return (-1);
		if (!(list->str = ft_strdup(newline + 1)))
			return (-1);
		ft_strdel(&tmp);
	}
	else
	{
		if (!(*line = ft_strdup(list->str)))
			return (-1);
		ft_strclr(list->str);
	}
	return (1);
}

/*
**	-->	Read_fd
**	Read in fd only if we can't find a '\n' in what we have already red
**	(= list->str).
*/

static int		read_fd(int fd, t_file *list)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	tmp = NULL;
	ret = 1;
	if (list->str == NULL)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if (!(list->str = ft_strjoin(list->str, buf)))
			return (-1);
	}
	while (!ft_strchr(list->str, '\n') && ret >= 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = 0;
		tmp = list->str;
		if (!(list->str = ft_strjoin(list->str, buf)))
			return (-1);
		ft_strdel(&tmp);
		if (ret == 0)
			return (0);
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static t_file		*file = NULL;
	t_file				*tmp;
	int					ret;

	if (fd < 0 || !line || read(fd, 0, 0) < 0)
		return (-1);
	if (!(tmp = get_file(fd, &file)))
		return (-1);
	if ((ret = read_fd(fd, tmp)) == -1)
		return (-1);
	if (fill_line(tmp, line) == -1)
		return (-1);
	if (!ft_strlen(tmp->str) && !ft_strlen(*line) && !ret)
		return (0);
	return (1);
}
