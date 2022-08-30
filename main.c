/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:46:52 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/30 14:56:31 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_piece(t_piece *piece)
{
	int i;
	
	i = 0;
	while (i < piece->size.h)
	{
		ft_strdel(&piece->array[i]);
		i++;
	}
	free(piece->array);
}

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

/* Initializing the structs. */
int	init(t_map *map, t_heat *heat, t_piece *piece)
{
	/* Here we set the map -struct : */
	ft_bzero(map, sizeof(*map));
	map->players_set = 0;
	map->player = "oO";
	map->opponent = "xX";
	/* Setting up the heat - struct */
	ft_bzero(heat, sizeof(*heat));
	heat->size.h = 0;
	heat->size.w = 0;
	/* Setting up the piece -struct */
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
	while(1)
	{
		if (!get_map(&map))
		{
			error_out("error : get map failed.");
			break;
		}
		if (!get_heat(&heat, &map))
		{
			error_out("error : failed to get heat.");
			break;
		}
		if (!get_piece(&piece))
		{
			error_out("error : failed to get piece.");
			break;
		}
		if (!play(&map, &heat, &piece))
			break;
		free_piece(&piece);
	}
	free_structs(&map, &heat, &piece);
	write_out(0, 0);
	system("leaks tburakow.filler 1<&2");
	return(0);
}
