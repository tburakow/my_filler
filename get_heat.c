/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:12:31 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/24 17:14:13 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	reset_map_copy(t_data **map_plr, t_heat **heatmap)
{
	int	i;

	i = 0;
	while (i < (*map_plr)->map_h)
	{
		ft_strcpy((*heatmap)->map_copy[i], (*map_plr)->map[i]);
		i++;
	}	
	return (OK);
}

int	check_occup(char c, t_data **map_plr)
{
	if (c == '.')
		return(OK);
	if (c == (*map_plr)->player || c == (*map_plr)->player + 32)
		return(ME);
	if (c == (*map_plr)->opponent || c == (*map_plr)->opponent + 32)
		return(OPP);
	return (KO);
}

void	parse_heat(t_data **map_plr, t_heat **heatmap, int h, int w)
{
	if (check_occup((*heatmap)->map_copy[h][w], map_plr) == OPP)
	{
		if (vector_calc(h - (*heatmap)->orig_h, w - (*heatmap)->orig_w) < (*heatmap)->heat)
			(*heatmap)->heat = vector_calc(h - (*heatmap)->orig_h, w - (*heatmap)->orig_w);
	}
	(*heatmap)->map_copy[h][w] = 'H';
	if ((h - 1) > MIN && check_occup((*heatmap)->map_copy[h - 1][w], map_plr))
		parse_heat(map_plr, heatmap, (h - 1), w);
	if ((h + 1) < (*heatmap)->h && check_occup((*heatmap)->map_copy[h + 1][w], map_plr))
		parse_heat(map_plr, heatmap, (h + 1), w);
	if ((w - 1) > MIN && check_occup((*heatmap)->map_copy[h][w - 1], map_plr))
		parse_heat(map_plr, heatmap, h, (w - 1));
	if ((w + 1) < (*heatmap)->w && check_occup((*heatmap)->map_copy[h][w + 1], map_plr))
		parse_heat(map_plr, heatmap, h, (w + 1));
	return;
}

int	calculate_heat(t_heat **heatmap, t_data **map_plr, int y, int x)
{
	if (!reset_map_copy(map_plr, heatmap))
		return (error_output(KO, "resetting map_copy failed."));
	(*heatmap)->heat = 1000000;
	(*heatmap)->orig_h = y;
	(*heatmap)->orig_w = x;
	(*heatmap)->map_copy[y][x] = 'H';
	parse_heat(map_plr, heatmap, y, x);
	(*heatmap)->array[y][x] = (*heatmap)->heat;
	return (OK);
}

int	get_heat(t_heat **heatmap, t_data **map_plr)
{
	int y;
	int x;

	y = 0;
	x = 0;
	//printf("Before pheat_whileloop\n");
	while (y < (*heatmap)->h)
	{
		x = 0;
		while (x < (*heatmap)->w)
		{
			if (check_occup((*map_plr)->map[y][x], map_plr) == OK)
			{
				if (!calculate_heat(heatmap, map_plr, y, x))
					return (error_output(KO, "error : heat calculation failed."));
				//printf("Hello!\n");
			}
			if (check_occup((*map_plr)->map[y][x], map_plr) == ME)
				(*heatmap)->array[y][x] = 0;
			x++;
		}
		y++;
	}
	//printf("After pheat_whileloop\n");
	return (OK);
}