/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:39:06 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/19 12:01:19 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* This function determines the "direction" of the players game. If the
player starts more to the up and left the direction is to right/low,
and vice-versa.  */
void	parse_direction(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < map->size.h)
	{
		x = 0;
		while (x < map->size.w)
		{
			if (map->array[y][x] != '.')
			{
				if (ft_toupper(map->array[y][x]) == map->player)
					map->dir = 'L';
				if (ft_toupper(map->array[y][x]) == map->opponent)
					map->dir = 'R';
			}
			x++;
		}
		y++;
	}
}

/* This function aims to patch the "leak" near the starting point of the player.
I.E. prevent the opponent from getting behind the player. */
int	adjust_to_time(t_map *map, int y, int x)
{
	if (map->turn > map->size.h * 2)
	{
		if (map->dir == 'L')
			if (y > map->size.h / 2 && x > map->size.w / 2)
				return (1);
		if (map->dir == 'R')
			if (y < map->size.h / 2 && x < map->size.w / 2)
				return (1);
	}
	return (0);
}
