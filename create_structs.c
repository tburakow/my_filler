/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:02:13 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/22 17:01:47 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int create_map(t_data **map_plr)
{
	*map_plr = (t_data *)ft_memalloc(sizeof(t_data));
	if (*map_plr == NULL)
		return (KO);
	(*map_plr)->players_set = 0;
	return (OK);
}

int	create_piece(t_piece **piece)
{
	*piece = (t_piece *)ft_memalloc(sizeof(t_piece));
	if (*piece == NULL)
		return (KO);
	return (OK);
}

int create_heatmap(t_heat **heatmap, t_data **map_plr)
{
	int	i;

	i = 0;
	*heatmap = (t_heat *)ft_memalloc(sizeof(t_heat));
	if (*heatmap == NULL)
		return (KO);
	(*heatmap)->w = ((*map_plr)->map_w);
	(*heatmap)->h = ((*map_plr)->map_h);
	(*heatmap)->array = (int **)malloc(sizeof(int *) * (*heatmap)->h);
	while (i < (*map_plr)->map_h)
	{
		(*heatmap)->array[i] = (int *)malloc(sizeof(int) * (*heatmap)->w);
		i++;
	}
	(*heatmap)->map_copy = (char **)malloc(sizeof(char *) * (*heatmap)->h);
	i = 0;
	while (i < (*map_plr)->map_h)
	{
		(*heatmap)->map_copy[i] = (char *)malloc(sizeof(char) * (*heatmap)->w);
		i++;
	}
	return (OK);
}