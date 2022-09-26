/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:06:27 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/26 20:16:27 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* This function switches the player to 'X', and opponent to 'O' */
void	switch_players(t_map *map)
{
	map->player = 'X';
	map->opponent = 'O';
}

/* This function determines which player the program should play as. */
int	get_player(t_map *map)
{
	char	*line;

	line = NULL;
	if (map->players_set == OK)
		return (OK);
	if (get_next_line(STDIN, &line) <= 0)
		return (sub_error_output("error : failed to read from line.\n"));
	if (ft_strchr(line, 'p') == KO)
	{
		ft_strdel(&line);
		return (sub_error_output("error : incorrect input on line.\n"));
	}
	if (ft_strstr(line, "tburakow.filler"))
	{
		if (ft_strstr(line, "p2"))
			switch_players(map);
	}
	else
	{
		ft_strdel(&line);
		return (sub_error_output("error : no matching player.\n"));
	}
	map->players_set = OK;
	ft_strdel(&line);
	return (OK);
}
