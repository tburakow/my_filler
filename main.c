/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:03:18 by tburakow          #+#    #+#             */
/*   Updated: 2022/07/21 14:12:14 by tburakow         ###   ########.fr       */
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

int	determine_player(char *name)
{
	char	*temp;
	int		i;
	
	i = 1;
	temp = (char *)malloc(sizeof(char) * 100);
	while(i < 3)
	{
		while (get_next_line(1, &temp) != 1)
		if (ft_strstr(temp, name) != NULL)
		{
			free(temp);
			return (i);
		}
		i++;
	}
	return (0);
}

int	init_struct(t_data **map_plr)
{
	char	*name = "tburakow.filler";
	
	*map_plr = (t_data *)ft_memalloc(sizeof(t_data));
	(*map_plr)->player = determine_player(name);
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
	
	if (init_struct(&map_plr) == 0)
	{
		ft_printf("error, struct creation failed.");
		exit(1);
	}
}