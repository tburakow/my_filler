/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:28:55 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/19 15:32:40 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_out_map(t_data **map_plr)
{
	int i;

	i = 0;
	while (i < (*map_plr)->map_h)
	{
		ft_printf("%s\n", (*map_plr)->map[i]);
		i++;
	}
}