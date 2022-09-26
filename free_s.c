/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:42:57 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/25 18:33:17 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size.h)
	{
		if (map->array[i])
			ft_strdel(&map->array[i]);
		map->array[i] = NULL;
		i++;
	}
	if (map->array)
		free(map->array);
}

void	free_heat(t_heat *heat)
{
	int	i;

	i = 0;
	while (i < heat->size.h)
	{
		if (heat->array[i])
			free(heat->array[i]);
		heat->array[i] = NULL;
		i++;
	}
	if (heat->array)
		free(heat->array);
}

void	free_piece(t_piece *piece)
{
	int	i;

	i = 0;
	while (i < piece->size.h)
	{
		if (piece->array[i])
			ft_strdel(&piece->array[i]);
		piece->array[i] = NULL;
		i++;
	}
	if (piece->array)
		free(piece->array);
}
