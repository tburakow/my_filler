/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:42:01 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/20 14:34:51 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	update_on_players(t_heat *heat, t_map *map, int i)
{
	int		j;

	j = 0;
	while (j < heat->size.w)
	{
		if (ft_toupper(map->array[i][j] == map->opponent))
			heat->array[i][j] = 1;
		if (ft_toupper(map->array[i][j] == map->player))
			heat->array[i][j] = -1;
		if (map->array[i][j] == '.')
			heat->array[i][j] = 0;
		j++;
	}
}

/* This function sets up the heatmap*/
int	heat_setup(t_heat *heat, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	heat->size.h = map->size.h;
	heat->size.w = map->size.w;
	if(!heat->queue)
		heat->queue = (t_slot *)ft_memalloc(sizeof(t_slot) * 4000);
	ft_bzero(heat->queue, 4000);
	heat->read = 0;
	heat->write = 0;
	if (!heat->array)
		heat->array = (int **)ft_memalloc(sizeof(int *) * heat->size.h);
	while (i < heat->size.h)
	{
		if (!heat->array[i])
			heat->array[i] = (int *)ft_memalloc(sizeof(int) * heat->size.w);
		ft_bzero(heat->array[i], heat->size.w);
		update_on_players(heat, map, i);
		i++;
	}
	return (OK);
}

/* This function sets the heat limit to match the longer 
of the two axis (x , y).
this ensures that there are no areas with "flat" heat, and also that the 
get_heat loop runs only the required amount of times. */
/* int	set_heat_limit(t_map *map)
{
	if (map->size.h > map->size.w)
		return (map->size.h);
	return (map->size.w);
} */

/* This function uses the check_heat_* -functions to 
find the lowest heat next to
the current cell. If a square occupied by
the opponent is found, the heat is set as '10'. */
int		parse_queue(t_heat *heat)
{
	while (read_queue())
}

void	create_queue_obj(t_heat *heat, t_coords *cell, int value)
{
	heat->queue[heat->write].value = value;
	heat->queue[heat->write].posit.x = cell->x;
	heat->queue[heat->write].posit.y = cell->y;
	heat->write++;
}

int	calculate_heat(t_heat *heat, t_coords *cell)
{
	int		cut;

	cut = 1;
	create_queue_obj(heat, cell, 1);
	//dprintf(2, "return = %d", returns);
	while (cut)
	{
		if (!parse_queue(heat))
			cut = 0;
	}
	//dprintf(2, "return = %d", returns);
	return (1);
}

/* This function iterates through the heatmap arrays, and calculates
the heat for each cell (coordinate) in the array. The smaller the
heat, the closer the opponent is. */
int	get_heat(t_heat *heat, t_map *map)
{
	t_coords	cell;
	int 		returns;
	int			value;
	//int			heat_limit;

	//heat_limit = set_heat_limit(map);
	cell.y = -1;
	cell.x = -1;
	value = 1;
	if (heat_setup(heat, map) != OK)
		return (sub_error_output("error : heat_map setup failed."));
	while (value)
	{
		while(++cell.y < heat->size.h)
		{
			cell.x = -1;
			while(++cell.x < heat->size.w)
			if (heat->array[cell.y][cell.x])
				value = calculate_heat(heat, &cell)
		}
	}
	fprint_out_heat(heat, "jee");
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
