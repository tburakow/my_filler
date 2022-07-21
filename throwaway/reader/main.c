/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:03:18 by tburakow          #+#    #+#             */
/*   Updated: 2022/07/21 13:25:22 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

int	init_struct(t_data **map_plr)
{
	
	
	*map_plr = (t_data *)ft_memalloc(sizeof(t_array));
	(*cols)->a_cutoff = a - 1;
	(*cols)->b_cutoff = 0;
	(*cols)->arr_a = (int *)malloc(sizeof(int) * a);
	(*cols)->arr_b = (int *)malloc(sizeof(int) * a);
	(*cols)->oper = 0; //Remove this is the final version.
	(*cols)->original_cutoff = a - 1;
	return (1);
}

int	main(void)
{
	t_data	map_plr;
	if (init_struct(&map_plr) == 0)
	{
		printf("error, struct creation failed.");
		exit(1);
	}
}