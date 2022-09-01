/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_to_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:45:45 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/31 14:51:47 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* This function adjusts the heat of the cell specified by the coordinates y and x,
if the middle of the map is not taken (i.e. early game), in which case the
middle of the map (middle third) is "hotter", and after the middle is taken, 
when the sides (thirds) are hotter. */
int	adjust_to_map(t_heat *heat, t_map *map, int y, int x)
{
	if (map->array[map->size.h / 2][map->size.w / 2] == '.')
	{
		if (y > map->size.h / 3 && y < map->size.h / 3 * 2 && x > 
		map->size.w / 3 && x < map->size.w / 3 * 2 && heat->array[y][x] > 2)
			return (1);
	}
	else if ((y < map->size.h / 3 || y > map->size.h / 3 * 2) && 
	(x < map->size.w / 3 || x > map->size.w / 3 * 2) && heat->array[y][x] > 2)
		return (1);
	return(0);
}