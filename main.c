/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:46:52 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/29 16:26:52 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	heat->heat = 100000;
	heat->orig.y = 0;
	heat->orig.x = 0;
	heat->size.h = 0;
	heat->size.w = 0;
	/* Setting up the piece -struct */
	ft_bzero(piece, sizeof(*piece));
	piece->orig.y = 0;
	piece->orig.x = 0;
	return (OK);
}

int	main(void)
{
	t_map		map;
	t_heat		heat;
	t_piece		piece;
	
	fprint_out_int(1, "-------- NEW RUN!!!!!-----");
	fprint_out_map(&map, "NEW RUN NEW RUN NEW RUN!!!!");
	if (!init(&map, &heat, &piece))
		error_out("error : init failed.");
	if (!get_player(&map))
		error_out("error : get player failed.");
	while (1)
	{
		if (!get_map(&map))
			error_out("error : get map failed.");
		if (!get_heat(&heat, &map))
			error_out("error : failed to get heat.");
		if (!get_piece(&piece))
			error_out("error : failed to get piece.");
/* 		if (!play(&map, &heat, &piece)) */
			break ;
	}
	write_out(0, 0);
	return (0);
}
