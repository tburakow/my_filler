/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:49:00 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/20 11:22:21 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* This function uses the heatmap to calculate the "score" for the piece's 
current position. a smaller score means a better position. If the score
attained is better than the former best, it's updated.*/
void	score_piece(t_heat *heat, t_piece *piece, t_coords *curr)
{
	int		score;
	int		i;
	int		j;

	i = 0;
	j = 0;
	score = 0;
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

/* This function validates the current position of the piece. It 
checks that there is only a single point of overlap between 
the piece and the already placed "player" pieces on the 
map, and no overlap between "player" and "opponent" -pieces. */
int	validate_place(t_map *map, t_piece *piece, t_coords *curr)
{
	t_coords	*spot;
	int			hits;
	int			crashes;

	spot = (t_coords *)ft_memalloc(sizeof(t_coords *));
	spot->y = -1;
	spot->x = -1;
	hits = 0;
	crashes = 0;
	while (++spot->y <= piece->end.y)
	{
		spot->x = -1;
		while (++spot->x <= piece->end.x)
		{
			if (piece->array[spot->y][spot->x] == '*')
			{
				hits += hits_and_crashes(map, map->player, curr, spot);
				crashes += hits_and_crashes(map, map->opponent, curr, spot);
			}
		}
	}
	free(spot);
	if (hits == 1 && crashes == 0)
		return (OK);
	return (KO);
}

/* This function iterates through the map (starting half the width/height
outside of the map to accomodate pieces with a lot of empty space)
searching for coordinates where the shape of the piece fits inside the
map's edges.*/
int	try_piece(t_map *map, t_heat *heat, t_piece *piece, t_coords *curr)
{
	int		return_value;

	piece->best_score = 1000000;
	curr->y = map->size.h / 2 * -1;
	curr->x = map->size.w / 2 * -1;
	return_value = 0;
	while (curr->y + piece->start.y < 0)
		curr->y++;
	while (curr->y + piece->end.y < map->size.h)
	{
		curr->x = map->size.w / 2 * -1;
		while (curr->x + piece->start.x < 0)
			curr->x++;
		while (curr->x + piece->end.x < map->size.w)
		{
			if (validate_place(map, piece, curr))
			{
				score_piece(heat, piece, curr);
				return_value = OK;
			}
			curr->x++;
		}
		curr->y++;
	}
	return (return_value);
}

/* This function checks whether a piece can be placed on the map. */
int	place_piece(t_map *map, t_heat *heat, t_piece *piece)
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

/* This function loops the player until a piece can no longer be placed. */
int	play(t_map *map, t_heat *heat, t_piece *piece)
{
	while (1)
	{
		map->turn++;
		if (!get_map(map))
		{
			return (sub_error_output("error : get map failed."));
			break ;
		}
		if (!get_heat(heat, map))
		{
			return (sub_error_output("error : failed to get heat."));
			break ;
		}
		if (!get_piece(piece))
		{
			return (sub_error_output("error : failed to get piece."));
			break ;
		}
		if (!place_piece(map, heat, piece))
			break ;
		free_piece(piece);
	}
	return (0);
}
