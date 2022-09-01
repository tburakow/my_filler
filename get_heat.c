/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:42:01 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/01 12:20:22 by tburakow         ###   ########.fr       */
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

/* This function sets the heat limit to match the longer of the two axis (x , y).
this ensures that there are no areas with "flat" heat, and also that the 
get_heat loop runs only the required amount of times. */
int set_heat_limit(t_map *map)
{
	if (map->size.h > map->size.w)
		return(map->size.h);
	return(map->size.w);
}

/* This function uses the check_for_heat function to find the lowest heat next to
the cell being checked (it does not check diagonals.) If a square occupied by
the opponent is found, the heat is set as '1'. */
int	calculate_heat(t_heat *heat, t_map *map, int y, int x)
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
	heat->array[y][x] = value;
	return (OK);
}

int	check_for_heat(t_heat *heat, t_map *map, int y, int x)
{
	if (ft_strchr(map->opponent, map->array[y][x]))
		return (1);
	else if (heat->array[y][x] > 0)
		return (heat->array[y][x] + 1);
	return (1000);
}

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
					return(sub_error_output("failed to calculate heat."));
				if (adjust_to_map(heat, map, y, x))
					heat->array[y][x]--;
				x++;
			}
			y++;
		}
		heat_limit--;
	}
	return (OK);
}