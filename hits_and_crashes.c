/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits_and_crashes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:12:50 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/21 14:20:39 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* This function checks if the character in map in the supplied coordinates
matches any character supplied in the string "s". */
int	hits_crashes(t_map *map, t_coords *curr, t_coords *spot)
{
	int	y;
	int	x;

	y = curr->y + spot->y;
	x = curr->x + spot->x;
	if (ft_toupper(map->array[y][x]) == map->opponent)
		return (2);
	if (ft_toupper(map->array[y][x]) == map->player)
		return (1);
	return (0);
}
