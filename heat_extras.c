/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_extras.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:45:45 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/19 20:22:33 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* This function increases the heat in the quarter of the map 
behind the opponent. */
int	adjust_to_direction(t_map *map, int y, int x)
{
	if (map->dir == 'R')
		if (y > map->size.h / 2 && x > map->size.w)
			return (1);
	if (map->dir == 'L')
		if (y < map->size.h / 2 && x < map->size.w)
			return (1);
	return (0);
}

/* Creates a line of "very hot" cells behind the opponent. */
void	force_to_edges(t_heat *heat, t_map *map, int y, int x)
{
	if (map->dir == 'R' && y == heat->size.h - 1 && x > heat->size.w / 2)
		heat->array[y][x] = 5;
	if (map->dir == 'L' && y == 0 && x < heat->size.w / 2)
		heat->array[y][x] = 5;
}

/* This function adjusts the heat of the cell specified by the coordinates 
y and x, if the middle of the map is not taken (i.e. early game), in which 
case the middle of the map (middle third) is "hotter", and after the 
middle is taken, when the sides (thirds) are hotter. The "hot center"
adjustment is not used for small maps(height under 25.) It's also time-
dependent, only working for a limited time.*/
int	adjust_to_map(t_heat *heat, t_map *map, int y, int x)
{
	if (map->array[map->size.h / 2][map->size.w / 2] == '.' && map->size.h > 25 \
	&& map->turn < map->size.h / 3)
	{
		if (y > map->size.h / 3 && y < map->size.h / 3 * 2 && x > \
		map->size.w / 3 && x < map->size.w / 3 * 2 && heat->array[y][x] > 2)
			return (1);
	}
	else if ((y < map->size.h / 3 || y > map->size.h / 3 * 2) && \
	(x < map->size.w / 3 || x > map->size.w / 3 * 2) && heat->array[y][x] > 2 \
	&& map->size.h > 25 && map->turn < map->size.h / 2 * 3)
		return (1);
	return (0);
}

void	heat_for_cells(t_get_heat *get_heat, int y, int x, int value)
{
	get_heat->heat->map_copy[y][x] = 'H';
	if (ft_toupper(get_heat->map->array[y][x]) == get_heat->map->opponent)
		value = 1;
	if (value < get_heat->heat->array[y][x])
		get_heat->heat->array[y][x] = value;
	if (y > 0)
		if (get_heat->heat->map_copy[y - 1][x] != 'H')
			heat_for_cells(get_heat, y - 1, x, value + 1);
	if (x > 0)
		if (get_heat->heat->map_copy[y][x - 1] != 'H')
			heat_for_cells(get_heat, y, x - 1, value + 1);
	if (y < get_heat->heat->size.h - 1)
		if (get_heat->heat->map_copy[y + 1][x] != 'H')
			heat_for_cells(get_heat, y + 1, x, value + 1);
	if (x < get_heat->heat->size.w - 1)
		if (get_heat->heat->map_copy[y][x + 1] != 'H')
			heat_for_cells(get_heat, y, x + 1, value + 1);
	if (y > 0 && x > 0)
		if (get_heat->heat->map_copy[y - 1][x - 1] != 'H')
			heat_for_cells(get_heat, y - 1, x - 1, value + 1);
	if (x > 0 && y < get_heat->heat->size.h - 1)
		if (get_heat->heat->map_copy[y][x - 1] != 'H')
			heat_for_cells(get_heat, y + 1, x - 1, value + 1);
	if (y < get_heat->heat->size.h - 1 && x < get_heat->heat->size.w - 1)
		if (get_heat->heat->map_copy[y + 1][x] != 'H')
			heat_for_cells(get_heat, y + 1, x + 1, value + 1);
	if (x < get_heat->heat->size.w - 1 && y > 0)
		if (get_heat->heat->map_copy[y][x + 1] != 'H')
			heat_for_cells(get_heat, y - 1, x + 1, value + 1);
	return;
}
