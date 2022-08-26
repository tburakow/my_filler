/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:29:28 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/26 17:34:29 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	skip_line(void)
{
	char	*line;
	
	line = NULL;
	(void)get_next_line(STDIN, &line);
	ft_strdel(&line);
}

int	fill_map(t_map *map)
{
	char	*line;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	if (!map->array)
		map->array = (char **)ft_memalloc(sizeof(char *) * map->size.h + 1);
	fprint_out_map(map, "start of fill_map :");
	while (i < map->size.h)
	{
		if (get_next_line(STDIN, &line) <= 0)
			return (sub_error_output("failed to read line for map_fill.\n"));
		j = 4;
		while (j < 5)
		{
			fprint_out_int(j, "j at fill_map");
			map->array[i] = ft_strdup(&line[j]);
			j++;
		}
		ft_strdel(&line);
		i++;
	}
	fprint_out_map(map, "end of fill_map :");
	return (OK);
}

int	get_map_size(t_map *map)
{
	char	*line;
	int		i;
	
	i = 0;
	line = NULL;
	if (get_next_line(STDIN, &line) <= 0)
		return(sub_error_output("error : failed to read line for mapsize\n"));
	if (ft_strstr(line, "Plateau"))
	{
		while(line[i])
		{
			if(ft_isdigit(line[i]))
			{
				if(!map->size.h)
					map->size.h = ft_atoi(&line[i]);
				else
					map->size.w = ft_atoi(&line[i]);
				while (ft_isdigit(line[i]))
					i++;
			}
			i++;
		}
	}
	else
	{
		ft_strdel(&line);
		return (sub_error_output("error : could not find Plateau\n"));
	}
	ft_strdel(&line);
	skip_line();
	fprint_out_map(map, "end of get_map_size :");
	return (OK);
}

int	get_map(t_map *map)
{
	if (!get_map_size(map))
		return (sub_error_output("error : failed to get map size\n"));
	if (!fill_map(map))
		return (sub_error_output("error : failed to fill map\n"));
	fprint_out_map(map, "end of get_map :");
	return (OK);
}
