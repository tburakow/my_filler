/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:46:52 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/18 19:30:16 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* Frees a struct of type t_piece. */
void	free_piece(t_piece *piece)
{
	int	i;

	i = 0;
	while (i < piece->size.h)
	{
		ft_strdel(&piece->array[i]);
		i++;
	}
	free(piece->array);
}

/* Frees all three major types of structs found in the program. */
void	free_structs(t_map *map, t_heat *heat, t_piece *piece)
{
	int	i;

	i = 0;
	while (i < map->size.h)
	{
		ft_strdel(&map->array[i]);
		i++;
	}
	free(map->array);
	i = 0;
	while (i < map->size.h)
	{
		free(heat->array[i]);
		heat->array[i] = NULL;
		i++;
	}
	free(heat->array);
	i = 0;
	while (i < piece->size.h)
	{
		ft_strdel(&piece->array[i]);
		i++;
	}
	free(piece->array);
}

/* This function writes out the coordinates for the placement of the 
current piece */
void	write_out(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

/* Initializes the three main structs. */
int	init(t_map *map, t_heat *heat, t_piece *piece)
{
	ft_bzero(map, sizeof(*map));
	map->players_set = 0;
	map->player = "oO";
	map->opponent = "xX";
	map->dir = 'Z';
	map->turn = 0;
	map->start.y = 100000;
	map->start.x = 100000;
	map->end.y = 0;
	map->end.x = 0;
	ft_bzero(heat, sizeof(*heat));
	heat->size.h = 0;
	heat->size.w = 0;
	ft_bzero(piece, sizeof(*piece));
	piece->start.y = 0;
	piece->start.x = 0;
	piece->end.y = 0;
	piece->end.x = 0;
	return (OK);
}

int	main(void)
{
	t_map		map;
	t_heat		heat;
	t_piece		piece;

	if (!init(&map, &heat, &piece))
		error_out("error : init failed.");
	if (!get_player(&map))
		error_out("error : get player failed.");
	while (1)
	{
		if (!play(&map, &heat, &piece))
			break ;
	}	
	free_structs(&map, &heat, &piece);
	write_out(0, 0);
	return (0);
}
