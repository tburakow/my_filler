/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:06:27 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/29 17:52:15 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_player(t_map *map)
{
	char	*line;
	
	line = NULL;
	if (map->players_set == OK)
		return (OK);
	if (get_next_line(STDIN, &line) <= 0)
		return(sub_error_output("error : failed to read from line to get player.\n"));
	if (ft_strchr(line, 'p') == KO)
	{
		ft_strdel(&line);
		return (sub_error_output("error : incorrect input on line.\n"));
	}
	if (ft_strstr(line, "tburakow.filler"))
	{
		if (ft_strstr(line, "p2"))
		{
			map->player = "xX";
			map->opponent = "oO";
		}
	}
	else
	{
		ft_strdel(&line);
		return(sub_error_output("error : no matching player.\n"));
	}
	map->players_set = OK;
	ft_strdel(&line);
/* 	fprint_out_map(map, "end of get_player :"); */
	return (OK);
}
