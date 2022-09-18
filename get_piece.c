/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:14:16 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/01 13:46:36 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* This function resets the start and end parameters in the piece. These
parameters are used to denote the rectangle containing the shape inside 
the piece. */
static void	reset_piece_actual(t_piece *piece)
{
	piece->start.y = 100000;
	piece->start.x = 100000;
	piece->end.y = 0;
	piece->end.x = 0;
}

/* This function iterates through the piece and finds the smallest rectangle
that holds the shape inside the piece. This is done in order to be able to 
place the piece near the edges (so that the coordinates are negative), and 
to save time when checking that the piece fits. */
int	get_piece_actual(t_piece *piece)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	reset_piece_actual(piece);
	while (++i < piece->size.h)
	{
		j = -1;
		while (++j < piece->size.w)
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
		}
	}
	return (OK);
}

/* Parses through the corresponding line read from standard input for
the piece "size" -attributes. */
static void	parse_piece_size(t_piece *piece, char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			if (!piece->size.h)
				piece->size.h = ft_atoi(&line[i]);
			else
				piece->size.w = ft_atoi(&line[i]);
			while (ft_isdigit(line[i]))
				i++;
		}
		i++;
	}
}

/* This function checks for the word "Piece" in the line read from 
standard input. this word denotes the line that contains the piece 
size information. */
int	get_piece_size(t_piece *piece)
{
	char	*line;

	piece->size.h = 0;
	piece->size.w = 0;
	if (get_next_line(STDIN, &line) <= 0)
		return (sub_error_output("error :failed to read line for piece size."));
	if (ft_strstr(line, "Piece") != NULL)
		parse_piece_size(piece, line);
	ft_strdel(&line);
	return (OK);
}

/* This function is for getting all the piece information from the standard 
output. */
int	get_piece(t_piece *piece)
{
	char	*line;
	int		i;

	i = 0;
	if (!get_piece_size(piece))
		return (sub_error_output("error : failed to get piece size."));
	piece->array = (char **)ft_memalloc(sizeof(char *) * piece->size.h + 1);
	while (i < piece->size.h)
	{
		if (get_next_line(STDIN, &line) < 0)
			return (sub_error_output("error : failed to read line for piece"));
		if (!piece->array[i])
			piece->array[i] = (char *)ft_memalloc(sizeof(char) \
			* piece->size.w + 1);
		piece->array[i] = ft_strcpy(piece->array[i], line);
		ft_strdel(&line);
		i++;
	}
	if (!get_piece_actual(piece))
		return (sub_error_output("error : failed to optimize piece."));
	ft_strdel(&line);
	return (OK);
}
