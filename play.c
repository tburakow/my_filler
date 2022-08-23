/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:31:44 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/23 16:08:52 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	reset_map(t_data **map_plr)
{
	int		i;
	char 	*line;

	i = 0;
	skip_line(&line);
	skip_line(&line);
	while (i < (*map_plr)->map_h)
	{
		if (get_next_line(STDIN, &line) <= 0)
			return (error_output(KO, "failed to reset map."));
		ft_strcpy((*map_plr)->map[i], line);
		i++;
	}
	return (OK);
}

void score_piece(t_heat **heatmap, t_piece **piece, t_coord *place)
{
	int score;
	int	i;
	int j;
	
	score = 0;
	i = place->h + (*piece)->top_left.h;
	j = place->w + (*piece)->top_left.w;
	while (i++ <= (*piece)->right_bottom.h)
	{
		while (j++ <= (*piece)->right_bottom.w)
		{
			if ((*piece)->array[i][j] == '*')
				score += (*heatmap)->array[i][j];
		}
	}
	if (score < (*piece)->best_score)
	{
		(*piece)->best_score = score;
		(*piece)->best.h = place->h;
		(*piece)->best.w = place->w;
	}
}

int		validate_place(t_data **map_plr, t_piece **piece, t_coord *place)
{
	int	i;
	int	j;
	int	hits;
	int crashes;

	i = place->h + (*piece)->top_left.h;
	j =	place->w + (*piece)->top_left.w;
	hits = 0;
	crashes = 0;
	while (i++ <= (*piece)->right_bottom.h)
	{
		while (j++ <= (*piece)->right_bottom.w)
		{
			if ((*map_plr)->map[i][j] == (*map_plr)->player && (*piece)->array[i][j] == (*map_plr)->player)
				hits++;
			if ((*map_plr)->map[i][j] == (*map_plr)->opponent && (*piece)->array[i][j] == (*map_plr)->opponent)
				crashes++;
		}
	}
	if (hits == 1 && crashes == 0)
		return (OK);
	return (KO);
}

/* This function iterates through the map, trying to place the piece in all spots
within the map's boundaries */
int		try_piece(t_data **map_plr, t_heat **heatmap, t_piece **piece)
{
	t_coord		*place;
	int			place_success;

	place = NULL;
	place->h = -20;
	place->w = -20;
	place_success = 0;
	(*piece)->best_score = 100000;
	while (place->h + (*piece)->top_left.h <= MIN)
		place->h ++;
	while (place->h - (*piece)->top_left.h > MIN && place->h + (*piece)->right_bottom.h < (*map_plr)->map_h)
	{
		place->w = -20;
		while (place->w  + (*piece)->top_left.w <= MIN)
			place->w ++;
		while (place->w  + (*piece)->top_left.w > MIN && place->w  + (*piece)->right_bottom.w < (*map_plr)->map_w)
		{
			if (validate_place(map_plr, piece, place))
			{
				score_piece(heatmap, piece, place);
				place_success = 1;
			}
			place->w++;
		}
		place->h++;
	}
	printf("%d %d\n", (*piece)->best.w, (*piece)->best.h);
	return (place_success);
}

int		play(t_data **map_plr, t_piece **piece, t_heat **heatmap)
{
	while (1)
	{
		if (!reset_map(map_plr))
			return (error_output(1, "Error, failed to fetch map (inside play)"));
		if (!get_piece(piece))
			return (error_output(1, "Error, failed to fetch piece (inside play)"));
		ft_printf("get_piece done.\n");
		if (!get_heat(heatmap, map_plr))
			return (error_output(1, "Error, failed to fetch heatmap (inside play)"));
		ft_printf("get_heat done.\n");
		if (try_piece(map_plr, heatmap, piece) != 1)
			break;
	}
	return (OK);
}