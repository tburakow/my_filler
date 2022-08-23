/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:31:44 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/23 17:43:45 by tburakow         ###   ########.fr       */
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
	while (i <= (*piece)->right_bottom.h)
	{
		j = place->w + (*piece)->top_left.w;
		while (j <= (*piece)->right_bottom.w)
		{
			if ((*piece)->array[i][j] == '*')
				score += (*heatmap)->array[i][j];
			j++;
		}
		i++;
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
	//printf("HALOO!\n");
	while (i <= (*piece)->right_bottom.h + (*piece)->top_left.h)
	{
		j = place->w + (*piece)->top_left.w;
		while (j <= (*piece)->right_bottom.w + (*piece)->top_left.w)
		{
			printf("map : %c   piece : %c   player : %c   h : %d W : %d   hits : %d crashes : %d\n  i : %d   j : %d\n", (*map_plr)->map[i][j], (*piece)->array[i][j], (*map_plr)->player, i, j, hits, crashes);
			if ((*map_plr)->map[i][j] == (*map_plr)->player && (*piece)->array[i][j] == '*')
				hits++;
			if ((*map_plr)->map[i][j] == (*map_plr)->opponent && (*piece)->array[i][j] == '*')
				crashes++;
			j++;
		}
		i++;
	}
	//printf("HELLO!");
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
	int			test_count;

	test_count = 0;
	place = (t_coord *)malloc(sizeof(t_coord));
	place->h = -20;
	place->w = -20;
	place_success = 0;
	(*piece)->best_score = 100000;
	while (place->h + (*piece)->top_left.h <= MIN)
		place->h ++;
	while (place->h + (*piece)->right_bottom.h < (*map_plr)->map_h)
	{
		place->w = -20;
		while (place->w  + (*piece)->top_left.w <= MIN)
			place->w ++;
		while (place->w  + (*piece)->right_bottom.w < (*map_plr)->map_w)
		{
			test_count++;
			printf("place_w : %d   r_b : %d   map_w : %d\n", place->w, (*piece)->right_bottom.w, (*map_plr)->map_w);
			if (validate_place(map_plr, piece, place) == OK)
			{
				printf("SCORING!");
				score_piece(heatmap, piece, place);
				place_success = 1;
			}
			place->w++;
		}
		place->h++;
	}
	printf("%d %d\n", (*piece)->best.w, (*piece)->best.h);
	free(place);
	return (place_success);
}

int		play(t_data **map_plr, t_piece **piece, t_heat **heatmap)
{
	while (1)
	{
		if (get_map(map_plr) != OK)
			return(error_output(KO, "Error: Fail to get map."));
		ft_printf("get_map done.\n");
		if (!create_heatmap(heatmap, map_plr))
			return(error_output(KO, "error : heatmap craetion failed."));
		ft_printf("heat map created done.\n");
		if (!get_piece(piece))
			return (error_output(1, "Error, failed to fetch piece (inside play)"));
		ft_printf("get_piece done.\n");
		printf("piece h: %d\n", (*piece)->whole.h);
		printf("piece w: %d\n", (*piece)->whole.w);
		if (!get_heat(heatmap, map_plr))
			return (error_output(1, "Error, failed to fetch heatmap (inside play)"));
		ft_printf("get_heat done.\n");
		if (try_piece(map_plr, heatmap, piece) != 1)
			break;
	}
	print_out_piece(&(*piece));
	print_out_map(&(*map_plr));
	printf("%c\n", (*map_plr)->player);
	return (OK);
}