/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:14:16 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/29 21:00:46 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_piece_actual(t_piece *piece)
{
	int i;
	int j;

	i = 0;
	j = 0;
	piece->start.y = 100000;
	piece->start.x = 100000;
	piece->end.y = 0;
	piece->end.x = 0;
	while (i < piece->size.h)
	{
		j = 0;
		while (j < piece->size.w)
		{
			if (piece->array[i][j] == '*')
			{
				if (i < piece->start.y)
					piece->start.y = i;
				if (j < piece->start.x)
					piece->start.x = j;
				if (i > piece->end.y)
					piece->end.y = i;
				if (j > piece->end.x)
					piece->end.x = j;
			}
			j++;
		}
		i++;
	}
	return (OK);
}

int		get_piece_size(t_piece *piece)
{
	char	*line;
	int		i;

	i = 0;
	piece->size.h = 0;
	piece->size.w = 0;
	if (get_next_line(STDIN, &line) <= 0)
		return(sub_error_output("error :failed to read line for piece size."));
	if (ft_strstr(line, "Piece") != NULL)
	{
		while(line[i])
		{
			if(ft_isdigit(line[i]))
			{
				if(!piece->size.h)
					piece->size.h = ft_atoi(&line[i]);
				else
					piece->size.w = ft_atoi(&line[i]);
				while (ft_isdigit(line[i]))
					i++;
			}
			i++;
		}
	}
	ft_strdel(&line);
	/* fprint_out_piece(piece, "at the end of get_piece_size."); */
	return (OK);
}

int		get_piece(t_piece *piece)
{
	char	*line;
	int		i;

	i = 0;
	if (!get_piece_size(piece))
		return(sub_error_output("error : failed to get piece size."));
	piece->array = (char **)ft_memalloc(sizeof(char *) * piece->size.h + 1);
	while (i < piece->size.h)
	{
		if (get_next_line(STDIN, &line) < 0)
			return (sub_error_output("error : failed to read line for piece"));
		piece->array[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	if (!get_piece_actual(piece))
		return (sub_error_output("error : failed to optimize piece."));
	ft_strdel(&line);
	/* fprint_out_piece(piece, "at the end of get_piece."); */
	return (OK);
}