/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:03:18 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/22 19:58:25 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	determine_player(t_data **map_plr)
{
	char *input;
	char *name = "tburakow.filler";
	
	input = NULL;
	if ((*map_plr)->players_set == OK)
		return (OK);
	if (get_next_line(STDIN, &input) <= 0)
		return(error_output(KO, "Error: Fail to read from STDIN."));
	if (ft_strchr(input, 'p') == NULL)
	{
		ft_strdel(&input);
		return(error_output(KO, "Error: incorrect input on line."));
	}
	if (ft_strstr(input, name) && ft_strstr (input, "p2"))
	{
		(*map_plr)->player = 'X';
		(*map_plr)->opponent = 'O';
	}
	else if (ft_strstr(input, name) && ft_strstr (input, "p1"))
	{
		(*map_plr)->player = 'O';
		(*map_plr)->opponent = 'X';
	}
	else
		return (error_output(KO, "player name mismatch."));
	(*map_plr)->players_set = OK;
	ft_strdel(&input);
	return (OK);
}

int	init(t_data **map_plr, t_heat **heatmap)
{
	if (determine_player(map_plr) == KO)
		return(error_output(1, "Error: Fail to determine players."));
	//ft_printf ("I am : %c\n", (*map_plr)->player);
	//ft_printf ("The opponent is : %c\n", (*map_plr)->opponent);
	if (get_map(map_plr) != OK)
		return(error_output(KO, "Error: Fail to get map."));
	ft_printf("get_map done.\n");
	if (!create_heatmap(heatmap, map_plr))
		return(error_output(KO, "error : heatmap craetion failed."));
	ft_printf("heat map created done.\n");
	return (OK);
}

int	main(void)
{
	t_data	*map_plr;
	t_piece *piece;
	t_heat	*heatmap;
	
	if (!create_map(&map_plr))
	{
		return(error_output(1, "error : failed to create map/player -struct."));
	}
	if (!create_piece(&piece))
	{
		return(error_output(1, "error : piece creation failed."));
	}
	if (init(&map_plr, &heatmap) != 1)
	{
		return(error_output(1, "error, map/piece creation failed."));
	}
	play(&map_plr, &piece, &heatmap);
	//printf("map width: %d\n", map_plr->map_w);
	//printf("map height: %d\n", map_plr->map_h);
	//print_out_map(&map_plr);
	//printf("piece h: %d\n", piece->h);
	//printf("piece w: %d\n", piece->w);
	print_out_piece(&piece);
	print_out_heatmap(&heatmap);
	//printf("%d\n", heatmap->array[3][3]);
	//printf("The end.\n");
	//while(1);
	print_out_map(&map_plr);
	//return (play(&map_plr, &piece, &heatmap));
}