/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:12:31 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/24 11:06:50 by tburakow         ###   ########.fr       */
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

int	calculate_heat(t_heat **heatmap, t_data **map_plr, int h, int w)
{
	if (!reset_map_copy(map_plr, heatmap))
		return (error_output(KO, "resetting map_copy failed."));
	(*heatmap)->heat = 1000000;
	(*heatmap)->orig_h = h;
	(*heatmap)->orig_w = w;
	(*heatmap)->map_copy[h][w] = 'H';
	parse_heat(map_plr, heatmap, h, w);
	(*heatmap)->array[h][w] = (*heatmap)->heat;
	return (OK);
}

int	get_heat(t_heat **heatmap, t_data **map_plr)
{
	int h;
	int w;

	h = 0;
	w = 0;
	//printf("Before pheat_whileloop\n");
	while (h < (*heatmap)->h)
	{
		w = 0;
		while (w < (*heatmap)->w)
		{
			if (check_occup((*map_plr)->map[h][w], map_plr) == OK)
			{
				if (!calculate_heat(heatmap, map_plr, h, w))
					return (error_output(KO, "error : heat calculation failed."));
				//printf("Hello!\n");
			}
			if (check_occup((*map_plr)->map[h][w], map_plr) == ME)
				(*heatmap)->array[h][w] = 0;
			w++;
		}
		h++;
	}
	//printf("After pheat_whileloop\n");
	return (OK);
}