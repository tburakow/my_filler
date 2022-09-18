/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_checks_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:05:23 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/18 18:54:10 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* Checks the cell above the current cell */
int	check_up(t_heat *heat, t_map *map, t_coords *cell, int value)
{
	if (ft_strchr(map->opponent, map->array[cell->y - 1][cell->x]))
		return (10);
	if (heat->array[cell->y - 1][cell->x] < value)
		return (heat->array[cell->y - 1][cell->x] + 1);
	return (value);
}

/* Checks the cell to the left of the current cell */
int	check_left(t_heat *heat, t_map *map, t_coords *cell, int value)
{
	if (ft_strchr(map->opponent, map->array[cell->y][cell->x - 1]))
		return (10);
	if (heat->array[cell->y][cell->x - 1] < value)
		return (heat->array[cell->y][cell->x - 1] + 1);
	return (value);
}

/* Checks the cell below the current cell */
int	check_down(t_heat *heat, t_map *map, t_coords *cell, int value)
{
	if (ft_strchr(map->opponent, map->array[cell->y + 1][cell->x]))
		return (10);
	if (heat->array[cell->y + 1][cell->x] < value)
		return (heat->array[cell->y + 1][cell->x] + 1);
	return (value);
}

/* Checks the cell to the right of the current cell */
int	check_right(t_heat *heat, t_map *map, t_coords *cell, int value)
{
	if (ft_strchr(map->opponent, map->array[cell->y][cell->x + 1]))
		return (10);
	if (heat->array[cell->y][cell->x + 1] < value)
		return (heat->array[cell->y][cell->x + 1] + 1);
	return (value);
}
