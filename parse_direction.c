/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:39:06 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/21 14:06:58 by tburakow         ###   ########.fr       */
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

/* This function handles the cases where memory allocation has failed. */
void	*handle_null(void *input, char *s)
{
	if (!input)
	{
		sub_error_output(s);
		exit(1);
	}
	return (input);
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
			if (adjust_to_direction(map, y, x))
				heat->array[y][x]--;
			x++;
		}
		y++;
	}
}
