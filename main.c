/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:03:18 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/11 14:54:31 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* int	determine_map_x()
{
	char	*temp;
	int		i;
	
	i = 1;
	temp = (char *)malloc(sizeof(char) * 100);
	while(i < 3)
	{
		if (ft_strstr(get_next_line(*temp, 1), name) != NULL)
		{
			free(temp);
			return (i);
		}
		i++;
	}
	return (0);
} */

int	determine_player(t_data **map_plr)
{
	char *input;
	char *name = "tburakow.filler";

	if ((*map_plr)->players_set == OK)
		return (OK);
	if (get_next_line(STDIN, &input) <= 0)
		return (KO);
	if (strchr(input, 'p') == NULL)
		return (KO);
	if (strstr(input, name) == NULL)
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
	return (OK);
}

int	init_struct(t_data **map_plr)
{
	if (determine_player(map_plr) == KO);
		return (KO);
	ft_printf ("I am : %c", (*map_plr)->player);
	ft_printf ("The opponent is : %c", (*map_plr)->opponent);
	get_map(map_plr);
/* 	(*map_plr)->map_x = determine_map_x();
	(*map_plr)->map_y = determine_map_y;
	(*map_plr)->map = 
	(*map_plr)->piece_x
	(*map_plr)->piece_y
	(*map_plr)->piece_fill */
	return (1);
}

int	main(void)
{
	t_data	*map_plr;

	if (!
	)
	if (init_struct(&map_plr) != 1)
	{
		ft_printf("error, struct creation failed.");
		exit(1);
	}
	//ft_printf("I am player %d\n", (map_plr)->player);
}