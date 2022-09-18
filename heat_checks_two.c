/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_checks_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:05:37 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/18 17:32:27 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_up_left(t_heat *heat, t_map *map, t_coords *cell, int value)
{
	if (ft_strchr(map->opponent, map->array[cell->y - 1][cell->x - 1]))
		return (10);
	if (heat->array[cell->y - 1][cell->x - 1] < value)
		return (heat->array[cell->y - 1][cell->x - 1] + 1);
	return (value);
}

int	check_down_left(t_heat *heat, t_map *map, t_coords *cell, int value)
{
	if (ft_strchr(map->opponent, map->array[cell->y + 1][cell->x - 1]))
		return (10);
	if (heat->array[cell->y + 1][cell->x - 1] < value)
		return (heat->array[cell->y + 1][cell->x - 1] + 1);
	return (value);
}

int	check_down_right(t_heat *heat, t_map *map, t_coords *cell, int value)
{
	if (ft_strchr(map->opponent, map->array[cell->y + 1][cell->x + 1]))
		return (10);
	if (heat->array[cell->y + 1][cell->x + 1] < value)
		return (heat->array[cell->y + 1][cell->x + 1] + 1);
	return (value);
}

int	check_up_right(t_heat *heat, t_map *map, t_coords *cell, int value)
{
	if (ft_strchr(map->opponent, map->array[cell->y - 1][cell->x + 1]))
		return (10);
	if (heat->array[cell->y - 1][cell->x + 1] < value)
		return (heat->array[cell->y - 1][cell->x + 1] + 1);
	return (value);
}
