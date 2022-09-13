/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_extras.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:45:45 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/13 18:13:57 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* This function adjusts the heat of the cell specified by the coordinates 
y and x, if the middle of the map is not taken (i.e. early game), in which 
case the middle of the map (middle third) is "hotter", and after the 
middle is taken, when the sides (thirds) are hotter. The "hot center"
adjustment is not used for small maps(height under 30.)*/
int	adjust_to_map(t_heat *heat, t_map *map, int y, int x)
{
	if (map->array[map->size.h / 2][map->size.w / 2] == '.' && map->size.h < 30)
	{
		if (y > map->size.h / 3 && y < map->size.h / 3 * 2 && x > \
		map->size.w / 3 && x < map->size.w / 3 * 2 && heat->array[y][x] >= 2)
			return (1);
	}
	else if ((y < map->size.h / 3 || y > map->size.h / 3 * 2) && \
	(x < map->size.w / 3 || x > map->size.w / 3 * 2) && heat->array[y][x] >= 2)
		return (1);
	return (0);
}

int	check_heat_axial(t_heat *heat, t_map *map, int y, int x)
{
	int		value;
	int		temp;

	value = 500;
	temp = 0;
	if (y > 0)
		temp = check_for_heat(heat, map, y - 1, x);
	if (temp < value)
		value = temp;
	if (x > 0)
		temp = check_for_heat(heat, map, y, x - 1);
	if (temp < value)
		value = temp;
	if (y + 1 < heat->size.h)
		temp = check_for_heat(heat, map, y + 1, x);
	if (temp < value)
		value = temp;
	if (x + 1 < heat->size.w)
		temp = check_for_heat(heat, map, y, x + 1);
	if (temp < value)
		value = temp;
	return (value);
}

int	check_heat_diagonal(t_heat *heat, t_map *map, int y, int x)
{
	int		value;
	int		temp;

	value = 500;
	temp = 0;
	if (y > 0 && x > 0)
		temp = check_for_heat(heat, map, y - 1, x -1);
	if (temp < value)
		value = temp;
	if (x > 0 && y + 1 < heat->size.h)
		temp = check_for_heat(heat, map, y + 1, x - 1);
	if (temp < value)
		value = temp;
	if (y + 1 < heat->size.h && x + 1 < heat->size.w)
		temp = check_for_heat(heat, map, y + 1, x + 1);
	if (temp < value)
		value = temp;
	if (x + 1 < heat->size.w && y > 0)
		temp = check_for_heat(heat, map, y - 1, x + 1);
	if (temp < value)
		value = temp;
	return (value);
}

/* This function checks the coordinate for the presence of "opponent"
chars, or a non-zero heat number. */
int	check_for_heat(t_heat *heat, t_map *map, int y, int x)
{
	if (ft_strchr(map->opponent, map->array[y][x]))
		return (1);
	else if (heat->array[y][x] > 0)
		return (heat->array[y][x] + 1);
	return (1000);
}
