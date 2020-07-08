/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 20:12:32 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/08 11:39:03 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	read_metadata(t_filler *filler)
{
	char *metadata;

	metadata = NULL;
	if (get_next_line(0, &metadata) < 0)
		return (-1);
	if (metadata[10] == '1')
	{
		filler->me->shape = 'O';
		filler->opponent->shape = 'X';
	}
	else if (metadata[10] == '2')
	{
		filler->me->shape = 'X';
		filler->opponent->shape = 'O';
	}
	else
	{
		ft_strdel(&metadata);
		return (-1);
	}
	ft_strdel(&metadata);
	return (0);
}

static int	map_sequence(t_filler *filler, const char *line)
{
	if (ft_strncmp(line, "Plateau", 7) == 0)
	{
		if (read_map(line, filler) < 0)
			return (-1);
	}
	return (0);
}

static int	piece_sequence(t_filler *filler, const char *line)
{
	if (read_piece(line, filler) < 0)
		return (-1);
	if (heatmap(filler) < 0)
		return (-1);
	if (play_piece(filler) < 0)
		return (-1);
	return (0);
}

static int	read_core(t_filler *filler)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (map_sequence(filler, (const char *)line) < 0)
		{
			ft_strdel(&line);
			return (-1);
		}
		else if (ft_strncmp(line, "Piece", 5) == 0)
		{
			if (piece_sequence(filler, (const char *)line) < 0)
			{
				ft_strdel(&line);
				return (-1);
			}
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}

int			main(void)
{
	t_filler filler;

	if (filler_init(&filler) < 0)
		return (1);
	if (read_metadata(&filler) < 0)
	{
		filler_clear(&filler);
		return (1);
	}
	if (read_core(&filler) < 0)
	{
		filler_clear(&filler);
		return (1);
	}
	filler_clear(&filler);
	return (0);
}
