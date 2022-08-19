/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:03:18 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/19 14:36:50 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int create_struct(t_data **map_plr)
{
	*map_plr = (t_data *)ft_memalloc(sizeof(t_data));
	if (*map_plr == NULL)
		return (KO);
	(*map_plr)->players_set = 0;
	return (OK);
}

int	determine_player(t_data **map_plr)
{
	char *input;
	char *name = "tburakow.filler";
	int el_ret;
	
	
	input = NULL;
	el_ret = get_next_line(STDIN, &input);
	ft_printf("it reads : %s\n", input);
	ft_printf("el_ret is : %d", el_ret);
	if ((*map_plr)->players_set == OK)
		return (OK);
	if (el_ret <= 0)
	{
		ft_printf("Error: Fail to read from STDIN\n");
		return (KO);
	}
	if (ft_strchr(input, 'p') == NULL)
	{
		ft_printf("Error: incorrect input on line.\n");
		ft_strdel(&input);
		return (KO);
	}
	if (ft_strstr(input, name) == NULL)
	{
		(*map_plr)->player = 'X';
		(*map_plr)->opponent = 'O';
	}
	else
	{
		(*map_plr)->player = 'O';
		(*map_plr)->opponent = 'X';
	}
	(*map_plr)->players_set = OK;
	(void)get_next_line(STDIN, &input);
	ft_strdel(&input);
	return (OK);
}

int	init_struct(t_data **map_plr)
{
	
	if (determine_player(map_plr) == KO)
	{
		ft_printf("Error: Fail to determine players.\n");
		return (KO);
	}
	ft_printf ("I am : %c\n", (*map_plr)->player);
	ft_printf ("The opponent is : %c\n", (*map_plr)->opponent);
	if (get_map(map_plr) != OK)
	{
		ft_printf("Error: Fail to get map.\n");
		return (KO);
	}
/*  (*map_plr)->map_x = determine_map_x();
	(*map_plr)->map_y = determine_map_y;
	(*map_plr)->map = 
	(*map_plr)->piece_x
	(*map_plr)->piece_y
	(*map_plr)->piece_fill */
	return (OK);
}

int	main(void)
{
	t_data	*map_plr;

	if (!create_struct(&map_plr))
	{
		ft_printf("error : failed to create map/player -struct\n");
		exit (1);
	}
	if (init_struct(&map_plr) != 1)
	{
		ft_printf("error, struct creation failed.\n");
		exit(1);
	}
	ft_printf("map width: %d\n", map_plr->map_w);
	ft_printf("map height: %d\n", map_plr->map_h);
	print_out_map(&map_plr);
	ft_printf("The end.\n");
	return (0);
}