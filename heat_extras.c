/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_extras.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:45:45 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/21 11:19:21 by tburakow         ###   ########.fr       */
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

/* This function checks uses the check_for_heat -function to check the squares
above/below and to left or right of the current square for enemy presence or
non-zero (i.e. set) heat value. */
int	check_heat_axial(t_heat *heat, t_coords *cell, int value)
{
	int		changes;

	changes = 0;
	if (cell->y > 0)
		changes += check_up(heat, cell, value);
	if (cell->x > 0)
		changes += check_left(heat, cell, value);
	if (cell->y + 1 < heat->size.h)
		changes += check_down(heat, cell, value);
	if (cell->x + 1 < heat->size.w)
		changes += check_right(heat, cell, value);
	return (changes);
}

/* This function checks uses the check_for_heat -function to check the squares
diagonally adjacent to the current square for enemy presence or
non-zero (i.e. set) heat value. */
int	check_heat_diag(t_heat *heat, t_coords *cell, int value)
{
	int		changes;

	changes = 0;
	if (cell->y > 0 && cell->x > 0)
		changes += check_up_left(heat, cell, value);
	if (cell->x > 0 && cell->y + 1 < heat->size.h)
		changes += check_down_left(heat, cell, value);
	if (cell->y + 1 < heat->size.h && cell->x + 1 < heat->size.w)
		changes += check_down_right(heat, cell, value);
	if (cell->x + 1 < heat->size.w && cell->y > 0)
		changes += check_up_right(heat, cell, value);
	return (changes);
}
