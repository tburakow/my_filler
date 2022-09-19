/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:42:01 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/19 20:30:55 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_set_a_lot(void *s, size_t n)
{
	size_t			i;
	int				*f;

	i = 0;
	f = s;
	while (i < n)
	{
		f[i] = 300;
		i++;
	}
}

int	create_map_copy(t_map *map, t_heat *heat)
{
	int		i;

	i = 0;
	if (!map->array || !heat)
		return (KO);
	if (!heat->map_copy)
		heat->map_copy = (char **)ft_memalloc(sizeof(char *) * heat->size.h + 1);
	while (i < map->size.h)
	{
		if (!heat->map_copy[i])
			heat->map_copy[i] = (char *)ft_memalloc(sizeof(char) * heat->size.w + 1);
		heat->map_copy[i] = ft_strcpy(heat->map_copy[i], map->array[i]);
		i++;
	}
	//fprint_out_heat(heat, "end of create_map_copy");
	return (OK);
}

/* This function sets up the heatmap*/
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
		ft_set_a_lot(heat->array[i], heat->size.w);
		i++;
	}
	//fprint_out_heat(heat, "hi!");
	if (!create_map_copy(map, heat))
		sub_error_output("error : map copy creation failed.");
	return (OK);
}

/* This function uses the check_heat_* -functions to 
find the lowest heat next to
the current cell. If a square occupied by
the opponent is found, the heat is set as '10'. */
int	generate_heat(t_heat *heat, t_map *map)
{
	t_get_heat	get_heat;
	int			y;
	int			x;

	y = -1;
	x = -1;
	get_heat.map = map;
	get_heat.heat = heat;
	while (++y < heat->size.h)
	{
		x= -1;
		while (++x < heat->size.w)
		if (ft_toupper(map->array[y][x]) == map->opponent)
		{
			heat_for_cells(&get_heat, y, x, 0);
			break;
		}	
	}
	fprint_out_heat(heat, "elvis");
	return (OK);
}

/* This function iterates through the heatmap arrays, and calculates
the heat for each cell (coordinate) in the array. The smaller the
heat, the closer the opponent is. */
int	get_heat(t_heat *heat, t_map *map)
{
	int			x;
	int			y;

	y = 0;
	x = 0;
	if (heat_setup(heat, map) != OK)
		return (sub_error_output("error : heat_map setup failed."));
	if (!generate_heat(heat, map))
		return (sub_error_output("error: heat generation failed."));
	run_adjustments(heat, map);
	return (OK);
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
			if (map->size.h < 20 && adjust_to_direction(map, y, x))
				heat->array[y][x] -= 2;
			if (map->size.h < 20 && adjust_to_time(map, y, x))
				heat->array[y][x] -= 2;
			force_to_edges(heat, map, y, x);
			x++;
		}
		y++;
	}
}
