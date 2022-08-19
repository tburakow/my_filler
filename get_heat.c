/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:12:31 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/19 20:52:01 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	is_free(char c)
{
	if (c != 'X' || c != 'x' || c != 'O' || c != 'o')
		return(KO);
	return (OK);
}

void parse_heat(t_cell **heat_cell, t_data **map_plr, int h, int w)
{
	int red;

	red = 0;
	printf("red :%d\n", red);
	if ((h - 1) > MIN && is_free((*map_plr)->map[h - 1][w]))
		parse_heat(heat_cell, map_plr, h - 1, w);
	if ((h + 1) < (*heat_cell)->max_h && is_free((*map_plr)->map[h + 1][w]))
		parse_heat(heat_cell, map_plr, h + 1, w);
	if ((w - 1) > MIN && is_free((*map_plr)->map[h][w - 1]))
		parse_heat(heat_cell, map_plr, h, w - 1);
	if ((w + 1) < (*heat_cell)->max_w && is_free((*map_plr)->map[h][w + 1]))
		parse_heat(heat_cell, map_plr, h, w + 1);
	if ((h - (*heat_cell)->orig_h) > (w - (*heat_cell)->orig_w))
		red = (h - (*heat_cell)->orig_h);
	else
		red = (w - (*heat_cell)->orig_w);
	printf("red :%d\n", red);
	(*heat_cell)->heat -= red;
	return;
}

int create_cell(t_cell **heat_cell, int h, int w, t_heat **heatmap)
{
	*heat_cell = (t_cell *)ft_memalloc(sizeof(t_cell));
	if (*heat_cell == NULL)
		return (KO);
	(*heat_cell)->orig_h = h;
	(*heat_cell)->orig_w = w;
	(*heat_cell)->max_h = (*heatmap)->h;
	(*heat_cell)->max_h = (*heatmap)->w;
	return (OK);
}

int	calculate_heat(t_heat **heatmap, t_data **map_plr, int h, int w)
{
	t_cell *heat_cell;
	
	if (!create_cell(&heat_cell, h, w, heatmap))
		return(error_output(KO, "error: Failed to create heat_cell"));
	heat_cell->heat = 100000;
	printf("Before parse\n");
	parse_heat(&heat_cell, map_plr, h, w);
	(*heatmap)->array[h][w] = heat_cell->heat;
	free(heat_cell);
	return (OK);
}

int	get_heat(t_heat **heatmap, t_data **map_plr)
{
	int h;
	int w;

	h = 0;
	w = 0;
	printf("Before pheat_whileloop\n");
	while (h < (*heatmap)->h)
	{
		w = 0;
		while (w < (*heatmap)->h)
		{
			if (is_free((*map_plr)->map[h][w]))
			{
				calculate_heat(heatmap, map_plr, h, w);
				printf("Hello!\n");
			}
			w++;
		}
		h++;
	}
	return (OK);
}