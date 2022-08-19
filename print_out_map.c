/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:28:55 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/19 19:52:29 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_out_map(t_data **map_plr)
{
	int i;

	i = 0;
	while (i < (*map_plr)->map_h)
	{
		ft_printf("%s\n", (*map_plr)->map[i]);
		i++;
	}
}

void	print_out_piece(t_piece **piece)
{
	int i;

	i = 0;
	while (i < (*piece)->h)
	{
		ft_printf("%s\n", (*piece)->array[i]);
		i++;
	}
}

void	print_out_heatmap(t_heat **heatmap)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < (*heatmap)->h)
	{
		j = 0;
		while (j < (*heatmap)->w)
		{
			ft_printf("%i ", (*heatmap)->array[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}