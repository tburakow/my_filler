/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_checks_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:05:23 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/19 21:48:17 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* Checks the cell above the current cell */
int	check_up(t_heat *heat, t_coords *cell, int value)
{
	if (heat->array[cell->y - 1][cell->x] == value)
	{
		heat->array[cell->y - 1][cell->x] = value + 1;
		return (1);
	}
	return (0);
}

/* Checks the cell to the left of the current cell */
int	check_left(t_heat *heat, t_coords *cell, int value)
{
	if (heat->array[cell->y][cell->x - 1] == value)
	{
		heat->array[cell->y][cell->x - 1] = value + 1;
		return (1);
	}
	return (0);
}

/* Checks the cell below the current cell */
int	check_down(t_heat *heat, t_coords *cell, int value)
{
	if (heat->array[cell->y + 1][cell->x] == value)
	{
		heat->array[cell->y + 1][cell->x] = value + 1;
		return (1);
	}
	return (0);
}

/* Checks the cell to the right of the current cell */
int	check_right(t_heat *heat, t_coords *cell, int value)
{
	if (heat->array[cell->y][cell->x + 1] == value)
	{
		heat->array[cell->y][cell->x + 1] = value + 1;
		return (1);
	}
	return (0);
}
