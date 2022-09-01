/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:42:01 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/01 12:56:18 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* This function sets up the heatmap  */
int	heat_setup(t_heat *heat, t_map *map)
{
	int		i;

	i = 0;
	heat->size.h = map->size.h;
	heat->size.w = map->size.w;
	if (!heat->array)
		heat->array = (int **)ft_memalloc(sizeof(int *) * heat->size.h);
	while (i < heat->size.h)
	{
		if (!heat->array[i])
			heat->array[i] = (int *)ft_memalloc(sizeof(int) * heat->size.w);
		ft_bzero(heat->array[i], heat->size.w);
		i++;
	}
	return (OK);
}

/* This function sets the heat limit to match the longer 
of the two axis (x , y).
this ensures that there are no areas with "flat" heat, and also that the 
get_heat loop runs only the required amount of times. */
int	set_heat_limit(t_map *map)
{
	if (map->size.h > map->size.w)
		return (map->size.h);
	return (map->size.w);
}

/* This function uses the check_heat_* -functions to 
find the lowest heat next to
the current cell. If a square occupied by
the opponent is found, the heat is set as '1'. */
int	calculate_heat(t_heat *heat, t_map *map, int y, int x)
{
	int		value;
	int		temp;

	value = 500;
	temp = 0;
	temp = check_heat_axial(heat, map, y, x);
	if (temp < value)
		value = temp;
	temp = check_heat_diagonal(heat, map, y, x);
	if (temp < value)
		value = temp;
	heat->array[y][x] = value;
	if (adjust_to_map(heat, map, y, x))
		heat->array[y][x]--;
	return (OK);
}

/* This function iterates through the heatmap arrays, and calculates
the heat for each cell (coordinate) in the array. The smaller the
heat, the closer the opponent is. */
int	get_heat(t_heat *heat, t_map *map)
{
	int			x;
	int			y;
	int			heat_limit;

	heat_limit = set_heat_limit(map);
	y = 0;
	x = 0;
	if (heat_setup(heat, map) != OK)
		return (sub_error_output("error : heat_map setup failed."));
	while (heat_limit > 0)
	{
		while (y < heat->size.h)
		{
			x = 0;
			while (x < heat->size.w)
			{
				if (!calculate_heat(heat, map, y, x))
					return (sub_error_output("failed to calculate heat."));
				x++;
			}
			y++;
		}
		heat_limit--;
	}
	return (OK);
}
