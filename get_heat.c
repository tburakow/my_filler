/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:42:01 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/25 19:12:47 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* This function updates the heat map to include the positions of 
both the player, and the opponent. */
void	update_on_players(t_heat *heat, t_map *map, int i)
{
	int		j;

	j = 0;
	while (j < heat->size.w)
	{
		if (ft_toupper(map->array[i][j] == map->opponent))
			heat->array[i][j] = -1;
		if (ft_toupper(map->array[i][j] == map->player))
			heat->array[i][j] = -2;
		if (map->array[i][j] == '.')
			heat->array[i][j] = 10000;
		j++;
	}
}

/* This function sets up the heatmap.
It's called once every turn of the game.*/
int	heat_setup(t_heat *heat, t_map *map)
{
	int		i;

	i = 0;
	heat->size.h = map->size.h;
	heat->size.w = map->size.w;
	if (!heat->array)
		heat->array = (int **)ft_memalloc(sizeof(int *) * heat->size.h);
	if (!handle_null(heat->array, "error: heat array allocation failed."))
		return (KO);
	while (i < heat->size.h)
	{
		if (!heat->array[i])
		{
			heat->array[i] = (int *)ft_memalloc(sizeof(int) * heat->size.w);
			if (!handle_null(heat->array[i], "error: heat array alloc failed."))
				return (KO);
		}
		ft_bzero(heat->array[i], heat->size.w);
		update_on_players(heat, map, i);
		i++;
	}
	return (OK);
}

/* This function calls the check_heat_axial and check_heat_diag -functions 
to set the surrounding cells to the correct value. If no cells are 
set, the heatmap has been filled. */
int	scan_adjacent_cells(t_heat *heat, t_coords *cell, int value)
{
	int		changes;

	changes = 0;
	changes += check_heat_axial(heat, cell, value);
	changes += check_heat_diag(heat, cell, value);
	return (changes);
}

/* This function iterates through the heat map, replacing the values
of the not-yet-set cells with the current value. */
int	heat_update(t_heat *heat, int target, int value)
{
	int			changes;
	t_coords	cell;

	cell.y = 0;
	cell.x = 0;
	changes = 0;
	while (cell.y < heat->size.h)
	{
		cell.x = 0;
		while (cell.x < heat->size.w)
		{
			if (heat->array[cell.y][cell.x] == target)
				changes += scan_adjacent_cells(heat, &cell, value);
			cell.x++;
		}
		cell.y++;
	}
	return (changes);
}

/* This function is the main function for getting the values for 
the heat map. The heat map is later used to place the pieces
to  optimal positions. */
int	get_heat(t_heat *heat, t_map *map)
{
	int		target;
	int		value;

	target = -1;
	value = 1;
	heat_setup(heat, map);
	while (heat_update(heat, target, value))
	{
		target = value;
		value++;
	}
	run_adjustments(heat, map);
	return (OK);
}
