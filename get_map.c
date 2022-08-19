/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:00:08 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/19 19:58:30 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	map_char(char c)
{
	if (c == '.' || c == 'o' || c == 'O' || c == 'x' || c == 'X')
		return (OK);
	return (KO);
}

int	fill_map(t_data **map_plr)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_printf("check 1\n");
	(*map_plr)->map = (char **)malloc(sizeof(char *) * (*map_plr)->map_h);
	while (i < (*map_plr)->map_h)
	{
		//ft_printf("check 2\n");
		if(get_next_line(STDIN, &line) <= 0)
			return (KO);
		//ft_printf("check 3\n");
		j = 0;
		while (line[j] != '\0')
		{
			//ft_printf("check 4\n");
			//ft_printf("%c", line[j]);
			if(map_char(line[j]) == OK)
			{
				//ft_printf("check 5\n");
				//ft_printf("line : %s\n", line);
				(*map_plr)->map[i] = ft_strdup(&line[j]);
				if ((*map_plr)->map[i] == NULL)
				{
					ft_printf("strdup fail.");
					return (KO);
				}
				//ft_printf("check 6\n");
				j += (*map_plr)->map_w - 1;
				//ft_printf("j : %d\n", j);
			}
			j++;
		}
		//ft_printf("i is: %d\n", i);
		//ft_printf("map_h is : %d\n", (*map_plr)->map_h);
		i++;
		ft_printf("check 8\n");
		ft_strdel(&line);
	}
	return (OK);
}

int get_map_size(t_data **map_plr)
{
	char	*input;
	int		i;

	i = 0;
	ft_printf("enter\n");
	if (get_next_line(STDIN, &input) <= 0)
	{
		ft_printf("error : failed to read line for map size.\n");
		return (KO);
	}

	if (ft_strstr(input, "Plateau") != NULL)
	{
		while(input[i])
		{
			if(ft_isdigit(input[i]))
			{
				if(!(*map_plr)->map_h)
					(*map_plr)->map_h = ft_atoi(&input[i]);
				else
					(*map_plr)->map_w = ft_atoi(&input[i]);
				while (ft_isdigit(input[i]))
					i++;
			}
			i++;
		}
	}
	ft_printf("Map size is ; width : %i. height : %i.\n", (*map_plr)->map_w, (*map_plr)->map_h);
	ft_strdel(&input);
	skip_line(&input);
	return (OK);
}

int get_map(t_data **map_plr)
{
	if (get_map_size(map_plr) != OK)
		return (KO);
	if (!fill_map(map_plr))
		return (KO);
	return (OK);
}