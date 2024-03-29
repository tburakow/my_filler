/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_checks_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:05:37 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/21 13:11:29 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_up_left(t_heat *heat, t_coords *cell, int value)
{
	if (heat->array[cell->y - 1][cell->x - 1] == 10000)
	{
		heat->array[cell->y - 1][cell->x - 1] = value;
		return (1);
	}
	return (0);
}

int	check_down_left(t_heat *heat, t_coords *cell, int value)
{
	if (heat->array[cell->y + 1][cell->x - 1] == 10000)
	{
		heat->array[cell->y + 1][cell->x - 1] = value;
		return (1);
	}
	return (0);
}

int	check_down_right(t_heat *heat, t_coords *cell, int value)
{
	if (heat->array[cell->y + 1][cell->x + 1] == 10000)
	{
		heat->array[cell->y + 1][cell->x + 1] = value;
		return (1);
	}
	return (0);
}

int	check_up_right(t_heat *heat, t_coords *cell, int value)
{
	if (heat->array[cell->y - 1][cell->x + 1] == 10000)
	{
		heat->array[cell->y - 1][cell->x + 1] = value;
		return (1);
	}
	return (0);
}
