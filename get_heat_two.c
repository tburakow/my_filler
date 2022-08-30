/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heat_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:42:01 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/30 14:54:50 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

int set_heat_limit(t_map *map)
{
	if (map->size.h > map->size.w)
		return(map->size.h - 1);
	return(map->size.w - 1);
}

int	calculate_heat(t_heat *heat, t_map *map, int y, int x)
{
	if (y > 0)
		heat->array[y][x] = check_for_heat(heat, map, y - 1, x);
	if (x > 0)
		heat->array[y][x] = check_for_heat(heat, map, y, x - 1);
	if (y + 1 < heat->size.h)
		heat->array[y][x] = check_for_heat(heat, map, y + 1, x);
	if (x + 1 < heat->size.w)
		heat->array[y][x] = check_for_heat(heat, map, y, x + 1);
	return (OK);
}

int	check_for_heat(t_heat *heat, t_map *map, int y, int x)
{
	if (ft_strchr(map->opponent, map->array[y][x]))
		return (1);
	else if (heat->array[y][x] > 0)
		return(heat->array[y][x] + 1);
	return (0);
}

int	get_heat(t_heat *heat, t_map *map)
{
	int			x;
	int			y;
	int			heat_value;
	int			heat_limit;

	heat_limit = set_heat_limit(map);
	heat_value = 0;
	y = 0;
	x = 0;
	if (heat_setup(heat, map) != OK)
		return (sub_error_output("error : heat_map setup failed."));
	while (heat_value < heat_limit)
	{
		while (y < heat->size.h)
		{
			x = 0;
			while (x < heat->size.w)
			{
				if (!calculate_heat(heat, map, y, x))
					return(sub_error_output("failed to calculate heat."));
				x++;
			}
			y++;
		}
		heat_value++;
	}
	/* fprint_out_heat(heat, "At the end of get_heat."); */
	/* fprint_out_map(map, "at the end of get_heat."); */
	return (OK);
}