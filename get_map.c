/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:34:56 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/11 14:15:55 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_map_size(t_data **map_plr)
{
	char	*map_string;
	int		i;
	int		i_o;

	i = 0;
	i_o = 1;
	(void)get_next_line(STDIN, &map_string);
	while(ft_isdigit(map_string[i]) != 1)
		i++;
	(*map_plr)->map_x = ft_atoi(&map_string[i]);
	while(ft_isdigit(map_string[i]) == 1)
		i++;
	i++;
	(*map_plr)->map_y = ft_atoi(&map_string[i]);
	free(map_string);
}