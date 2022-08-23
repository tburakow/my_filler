/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:31:44 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/23 14:52:33 by tburakow         ###   ########.fr       */
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

/* This function iterates through the map, trying to place the piece in all spots
within the map's boundaries */
int		try_piece(t_data **map_plr, t_heat **heatmap, t_piece **piece)
{
	int		i;
	int		j;

	i = -20;
	j = -20;
	while (i + (*piece)->top_left.h <= MIN)
		i++;
	while (i - (*piece)->top_left.h > MIN && i + (*piece)->right_bottom.h < (*map_plr)->map_h)
	{
		j = -20;
		while (j + (*piece)->top_left.w <= MIN)
			j++;
		while (j + (*piece)->top_left.w > MIN && j + (*piece)->right_bottom.w < (*map_plr)->map_w)
		{
			if (validate_place(map_plr, heatmap, piece))
				place_piece(map_plr, heatmap, piece);
			j++;
		}
		i++;
	}
	return (OK);
}

int		play(t_data **map_plr, t_piece **piece, t_heat **heatmap)
{
	//while (1)
	//{
		if (!reset_map(map_plr))
			return (error_output(1, "Error, failed to fetch map (inside play)"));
		if (!get_piece(piece))
			return (error_output(1, "Error, failed to fetch piece (inside play)"));
		ft_printf("get_piece done.\n");
		if (!get_heat(heatmap, map_plr))
			return (error_output(1, "Error, failed to fetch heatmap (inside play)"));
		ft_printf("get_heat done.\n");
/* 		if (place_piece(map_plr, heatmap, piece) == 2);
			break; */
	//}
	return (0);
}