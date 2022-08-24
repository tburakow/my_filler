/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:31:44 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/24 16:44:16 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* int	reset_map(t_data **map_plr)
{
	int		i;
	char 	*line;

	i = 0;
	(void)skip_line();
	(void)skip_line();
	while (i < (*map_plr)->map_h)
	{
		if (get_next_line(STDIN, &line) <= 0)
			return (error_output(KO, "failed to reset map."));
		ft_strcpy((*map_plr)->map[i], line);
		i++;
	}
	return (OK);
} */

/* void score_piece(t_heat **heatmap, t_piece **piece, t_coord *place)
{
	int score;
	int	i;
	int j;
	
	score = 0;
	i = 0;
	j = 0;
	fprint_string("start of score_piece\n");
	while (i <= (*piece)->right_bottom.h)
	{
		j = 0;
		while (j <= (*piece)->right_bottom.w)
		{
			if ((*piece)->array[i][j] == '*')
				score += (*heatmap)->array[i + place->h][j + place->w];
			j++;
		}
		dprintf(2, "score : %d", score);
		i++;
	}
	if (score < (*piece)->best_score)
	{
		(*piece)->best_score = score;
		(*piece)->best.h = place->h;
		(*piece)->best.w = place->w;
	}
	fprint_string("end of score_piece\n");
	return;
} */

void	score_piece(t_heat **heatmap, t_piece **piece, t_coord *place)
{
	int	score;
	int i;
	int j;

	score = 0;
	i = 0;
	j = 0;
	while (i <= (*piece)->right_bottom.h && place->h + i < (*heatmap)->h)
	{
		j = 0;
		while (j <= (*piece)->right_bottom.h && place->w + j < (*heatmap)->w)
		{
			if ((*piece)->array[i][j] == '*')
			{
				dprintf(2, "Ping!\n");
				score += (*heatmap)->array[i + place->h][j + place->w];
			}
			j++;
		}
		dprintf(2, "score : %d\n", score);
		i++;
	}
	if (score < (*piece)->best_score)
	{
		(*piece)->best_score = score;
		(*piece)->best.h = place->h;
		(*piece)->best.w = place->w;
	}
	fprint_string("end of score_piece\n");
}

/* int		validate_place(t_data **map_plr, t_piece **piece, t_coord *place)
{
	int	i;
	int	j;
	int	hits;
	int crashes;

	i = 0;
	j =	0;
	hits = 0;
	crashes = 0;
	//fprint_string("start of validate_piece\n");
	//printf("HALOO!\n");
	//printf("map : %c   piece : %c   player : %c   h : %d W : %d   hits : %d crashes : %d\n\n", (*map_plr)->map[i][j], (*piece)->array[i][j], (*map_plr)->player, i, j, hits, crashes);
	while (i <= (*piece)->right_bottom.h)
	{
		j = 0;
		while (j <= (*piece)->right_bottom.w)
		{
			fprint_string("j  & right_botoom.w :\n");
			fprint_int(j);
			fprint_int((*piece)->right_bottom.w);
			//printf("map : %c   piece : %c   player : %c   h : %d W : %d   hits : %d crashes : %d\n\n", (*map_plr)->map[i][j], (*piece)->array[i][j], (*map_plr)->player, i, j, hits, crashes);
			if ((*map_plr)->map[i + place->h][j + place->w] == (*map_plr)->player && (*piece)->array[i][j] == '*')
				hits++;
			fprint_string("\ni + place->h & j + place->w :\n");
			fprint_int(i + place->h);
			fprint_int(j + place->w);
			if ((*map_plr)->map[i + place->h][j + place->w] == (*map_plr)->player  + 32 && (*piece)->array[i][j] == '*')
				hits++;
			if ((*map_plr)->map[i + place->h][j + place->w] == (*map_plr)->opponent && (*piece)->array[i][j] == '*')
				crashes++;
			if ((*map_plr)->map[i + place->h][j + place->w] == (*map_plr)->opponent + 32 && (*piece)->array[i][j] == '*')
				crashes++;
			j++;
		}
		i++;
	}
	//printf("HELLO!");
	//fprint_string("end of validate_piece\n");
	if (hits == 1 && crashes == 0)
		return (OK);
	return (KO);
} */
int		validate_place(t_data **map_plr, t_piece **piece, t_coord *place)
{
	int		i;
	int		j;
	int		hits;
	int		crashes;

	hits = 0;
	crashes = 0;
	i = 0;
	j = 0;
	while (i <= (*piece)->right_bottom.h && place->h + i < (*map_plr)->map_h)
	{
		j = 0;
		while (j <= (*piece)->right_bottom.h && place->w + j < (*map_plr)->map_w)
		{
			if ((*piece)->array[i][j] == '*')
			{
				if ((*map_plr)->map[i + place->h][j + place->w] == (*map_plr)->player)
					hits++;
				if ((*map_plr)->map[i + place->h][j + place->w] == (*map_plr)->player + 32)
					hits++;
				if ((*map_plr)->map[i + place->h][j + place->w] == (*map_plr)->opponent + 32)
					crashes++;
				if ((*map_plr)->map[i + place->h][j + place->w] == (*map_plr)->opponent)
					crashes++;	
			}
			j++;
		}
		i++;
	}
	if (hits == 1 && crashes == 0)
	{
		dprintf(2, "Valid place!\n");
		return (OK);
	}
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
	fprint_string("start of try_piece\n");
	//printf("current best : %d %d score : %d\n", (*piece)->best.w, (*piece)->best.h, (*piece)->best_score);
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
			//printf("place_w : %d place_h :  %d  r_b : %d   map_w : %d\n", place->w, place->h, (*piece)->right_bottom.w, (*map_plr)->map_w);
			if (validate_place(map_plr, piece, place) == OK)
			{
				//print_out_heatmap(heatmap);
				//printf("SCORING!");
				score_piece(heatmap, piece, place);
				//printf("current best : %d %d score : %d\n", (*piece)->best.w, (*piece)->best.h, (*piece)->best_score);
				place_success = 1;
			}
			place->w++;
		}
		place->h++;
		
	}
	fprint_string("best.w is :");
	fprint_int((*piece)->best.w);
	fprint_string("best.h is :");
	fprint_int((*piece)->best.h);
	free(place);
	fprint_string("end of try_piece\n");
	return (place_success);
}

int		play(t_data **map_plr, t_piece **piece, t_heat **heatmap)
{
	while (1)
	{
		fprint_string("start of play.\n");
		if (get_map(map_plr) != OK)
			return(error_output(KO, "Error: Fail to get map."));
		fprint_out_map(map_plr);
		fprint_string("after getmap.\n");
		//ft_printf("get_map done.\n");
		if (!create_heatmap(heatmap, map_plr))
			return(error_output(KO, "error : heatmap creation failed."));
		fprint_string("after create heat\n");
		//ft_printf("heat map created done.\n");
		if (!get_piece(piece))
			return (error_output(1, "Error, failed to fetch piece (inside play)"));
		fprint_out_piece(piece);
		//ft_printf("get_piece done.\n");
		//printf("piece h: %d\n", (*piece)->whole.h);
		//printf("piece w: %d\n", (*piece)->whole.w);
		fprint_string("after get piece\n");
		if (!get_heat(heatmap, map_plr))
			return (error_output(1, "Error, failed to fetch heatmap (inside play)"));
		//ft_printf("get_heat done.\n");
		fprint_string("after get heat\n");
		if (try_piece(map_plr, heatmap, piece) != 1)
			break;
		printf("%d %d\n", (*piece)->best.h, (*piece)->best.w);
		fprint_string("after try piece\n");
		fprint_string("end of play.");
	}
	//print_out_piece(&(*piece));
	//print_out_map(&(*map_plr));
	//printf("%c\n", (*map_plr)->player);
	return (OK);
}