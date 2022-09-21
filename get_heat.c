/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:42:01 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/21 11:31:43 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	update_on_players(t_heat *heat, t_map *map, int i)
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
			heat->array[i][j] = 0;
		j++;
	}
}

/* This function sets up the heatmap*/
int	heat_setup(t_heat *heat, t_map *map)
{
	int		i;

	i = 0;
	heat->size.h = map->size.h;
	heat->size.w = map->size.w;
	if (!heat->array)
		heat->array = (int **)ft_memalloc(sizeof(int *) * heat->size.h);
	handle_null(heat->array, "error: heat array allocation failed.");
	while (i < heat->size.h)
	{
		if (!heat->array[i])
			heat->array[i] = (int *)ft_memalloc(sizeof(int) * heat->size.w);
		handle_null(heat->array[i], "error: heat array allocation failed.");
		ft_bzero(heat->array[i], heat->size.w);
		update_on_players(heat, map, i);
		i++;
	}
	return (OK);
}

static int	scan_adjacent_cells(t_heat *heat, t_coords *cell, int value)
{
	int		changes;

	changes = 0;
	changes += check_heat_axial(heat, cell, value);
	changes += check_heat_diag(heat, cell, value);
	return(changes);
}

static int	heat_update(t_heat *heat, int target, int value)
{
	int 		changes;
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


int	get_heat(t_heat *heat, t_map *map)
{
	int		target;
	int		value;

	target = -1;
	value = 1;
	while (heat_update(heat, target, value) != 0)
	{
		dprintf(2, "target = %d", target);
		dprintf(2, "value = %d", value);
		target = value;
		value++;
	}
	run_adjustments(heat, map);
	return (OK);
}

/*This function runs some map-size specific, and time specific adjustments
on the ehat of each shell*/
void	run_adjustments(t_heat *heat, t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < heat->size.h)
	{
		x = 0;
		while (x < heat->size.w)
		{
			if (adjust_to_map(heat, map, y, x))
				heat->array[y][x]--;
			if (map->size.h < 20 && adjust_to_direction(map, y, x))
				heat->array[y][x] -= 2;
			if (map->size.h < 20 && adjust_to_time(map, y, x))
				heat->array[y][x] -= 2;
			force_to_edges(heat, map, y, x);
			x++;
		}
		y++;
	}
}
