/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:37:26 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/26 19:43:40 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	reset_map_copy(t_heat *heat, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size.h)
	{
		ft_strcpy(heat->map_copy[i], map->array[i]);
		i++;
	}	
	return (OK);
}

void	parse_heat(t_heat *heat, t_map *map, int y, int x)
{
	int		temp_heat;
	
	temp_heat = (int)(10 * simple_vector_length(y - heat->orig.y, x - heat->orig.x));
	if (ft_strchr(map->opponent, map->array[y][x]) != NULL)
		if (temp_heat < heat->heat)
			heat->heat = temp_heat;
	heat->map_copy[y][x] = 'H';
	if (y - 1 > MIN && heat->map_copy[y - 1][x] != 'H')
		parse_heat(heat, map, y - 1, x);
	if (y + 1 < map->size.h && heat->map_copy[y + 1][x] != 'H')
		parse_heat(heat, map, y + 1, x);
	if (x - 1 > MIN && heat->map_copy[y][x - 1] != 'H')
		parse_heat(heat, map, y, x - 1);
	if (x + 1 < map->size.w && heat->map_copy[y][x + 1] != 'H')
		parse_heat(heat, map, y, x + 1);
	return ;
}

int	calculate_heat(t_heat *heat, t_map *map, int y, int x)
{
	if (!reset_map_copy(heat, map))
		return (sub_error_output("error : reset map_copy failed."));
	heat->heat = 1000000;
	heat->orig.y = y;
	heat->orig.x = x;
	heat->map_copy[y][x] = 'H';
	parse_heat(heat, map, y, x);
	heat->array[y][x] = heat->heat;
	fprint_out_heat(heat, "At the end of calculate_heat.");
	fprint_out_map(map, "at the end of calculate_heat.");
	return (OK);
}

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
	if (!heat->map_copy)
		heat->map_copy = (char **)ft_memalloc(sizeof(char *) * map->size.h + 1);
	i = 0;
	while (i < map->size.h)
	{
		if (!heat->map_copy[i])
			heat->map_copy[i] = (char *)ft_memalloc(sizeof(char) * map->size.w + 1);
		i++;
	}
	return (OK);
}

int	get_heat(t_heat *heat, t_map *map)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	if (heat_setup(heat, map) != OK)
		return (sub_error_output("error : heat_map setup failed."));
	while (y < heat->size.h)
	{
		x = 0;
		while (x < heat->size.w)
		{
			if (map->array[y][x] == '.')
				if (calculate_heat(heat, map, y, x) == KO)
					return (sub_error_output("error : fail to calculate heat for square."));
			x++;
		}
		y++;
	}
	fprint_out_heat(heat, "At the end of get_heat.");
	fprint_out_map(map, "at the end of get_heat.");
	return (OK);
}