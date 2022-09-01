/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:49:00 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/31 13:46:39 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	score_piece(t_heat *heat, t_piece *piece, t_coords *curr)
{
	int		score;
	int		i;
	int		j;

	i = 0;
	j = 0;
	score = 0;
	/* fprint_out_piece(piece, "start of score piece."); */
	while (i <= piece->end.y)
	{
		j = 0;
		while (j <= piece->end.x)
		{
			if (piece->array[i][j] == '*')
				score += heat->array[i + curr->y][j + curr->x];
			j++;
		}
		i++;
	}
	if (score < piece->best_score)
	{
		piece->best.y = curr->y;
		piece->best.x = curr->x;
		piece->best_score = score;
	}
}

int	hits_and_crashes(t_map *map, char *s, t_coords *curr, t_coords *spot)
{
	int y;
	int x;

	y = curr->y + spot->y;
	x = curr->x + spot->x;
	if (ft_strchr(s, map->array[y][x]))
		return (1);
	return (0);
}

int	validate_place(t_map *map, t_piece *piece, t_coords *curr)
{
	t_coords	*spot;
	int			hits;
	int 		crashes;

	/* fprint_out_piece(piece, "start of validate piece."); */
	spot = (t_coords *)ft_memalloc(sizeof(t_coords *));
	spot->y = 0;
	spot->x = 0;
	hits = 0;
	crashes = 0;
/* 	dprintf(2, "piece->size.h : %d\n", piece->size.h);
	dprintf(2, "piece->size.w : %d\n", piece->size.w);
	dprintf(2, "piece->end.x : %d\n", piece->end.x);
	dprintf(2, "piece->end.y : %d\n", piece->end.y); */
	while (spot->y <= piece->end.y)
	{
		spot->x = 0;
		while (spot->x <= piece->end.x)
		{
			/* dprintf(2, "spot->y : %d, spot->x : %d\n", spot->y, spot->x); */
			if (piece->array[spot->y][spot->x] == '*')
			{
				hits += hits_and_crashes(map, map->player, curr, spot);
				crashes += hits_and_crashes(map, map->opponent, curr, spot);
			}
			spot->x++;
		}
		spot->y++;
	}
	free(spot);
	if (hits == 1 && crashes == 0)
		return (OK);
	return (KO);
}

int	try_piece(t_map *map, t_heat *heat, t_piece *piece, t_coords *curr)
{
	int		return_value;

	piece->best_score = 1000000;
	curr->y = map->size.h / 2 * -1;
	curr->x = map->size.w / 2 * -1;
	/* fprint_out_piece(piece, "start of try piece."); */
	return_value = 0;
	while (curr->y + piece->start.y < 0)
		curr->y++;
	while (curr->y + piece->end.y < map->size.h)
	{
		//dprintf(2, "y + y : %d  size.h : %d\n", curr->y + piece->end.y, map->size.h);
		curr->x = map->size.w / 2 * -1;
		while (curr->x + piece->start.x < 0)
			curr->x++;
		while (curr->x + piece->end.x < map->size.w)
		{
			//dprintf(2, "x + x : %d  size.w : %d\n", curr->x + piece->end.x, map->size.w);
			if (validate_place(map, piece, curr))
			{
				score_piece(heat, piece, curr);
				return_value = OK;
			}
			curr->x++;
		}
		curr->y++;
	}
	/* fprint_out_piece(piece, "end of try piece."); */
	return (return_value);
}

int	play(t_map *map, t_heat *heat, t_piece *piece)
{
	t_coords	*curr;
	int			piece_placed;
	
	curr = (t_coords *)ft_memalloc(sizeof(t_coords));
	piece_placed = 0;
	if (try_piece(map, heat, piece, curr))
	{
		piece_placed = 1;
		write_out(piece->best.y, piece->best.x);
	}
	free(curr);
	return (piece_placed);	
}