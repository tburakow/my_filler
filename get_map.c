/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:29:28 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/20 13:54:25 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* This function is used to read and delete (skip) a line read 
from the standard input; */
void	skip_line(void)
{
	char	*line;

	line = NULL;
	(void)get_next_line(STDIN, &line);
	ft_strdel(&line);
}

/* This function fills the map->array coordinates with the current characters
found on the map */
int	fill_map(t_map *map)
{
	char	*line;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!map->array)
		map->array = (char **)ft_memalloc(sizeof(char *) * map->size.h + 1);
	handle_null(map->array, "error: map_array not allocated.");
	while (++i < map->size.h)
	{
		if (get_next_line(STDIN, &line) <= 0)
			return (sub_error_output("failed to read line for map_fill.\n"));
		j = 3;
		while (++j < 5)
		{
			if (!map->array[i])
				map->array[i] = (char *)ft_memalloc(sizeof(char) \
				* map->size.w + 1);
			handle_null(map->array[i], "error: map array row alloc.failed.");
			map->array[i] = ft_strcpy(map->array[i], &line[j]);
		}
		ft_strdel(&line);
	}
	return (OK);
}

/* This function parses through the corresponding line
read from standard input for the map size. */
void	parse_map_size(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			if (!map->size.h)
				map->size.h = ft_atoi(&line[i]);
			else
				map->size.w = ft_atoi(&line[i]);
			while (ft_isdigit(line[i]))
				i++;
		}
		i++;
	}
}

/* This map reads the line with the map size information from std input, and 
writes them to the struct. */
int	get_map_size(t_map *map)
{
	char	*line;

	line = NULL;
	if (get_next_line(STDIN, &line) < 0)
		return (sub_error_output("error : failed to read line for mapsize\n"));
	if (ft_strstr(line, "Plateau"))
		parse_map_size(map, line);
	else
	{
		ft_strdel(&line);
		return (sub_error_output("error : could not find Plateau\n"));
	}
	ft_strdel(&line);
	skip_line();
	return (OK);
}

/* This function gets the map size and the character strings that
 the map is comprised of */
int	get_map(t_map *map)
{
	if (!get_map_size(map))
		return (sub_error_output("error : failed to get map size\n"));
	if (!fill_map(map))
		return (sub_error_output("error : failed to fill map\n"));
	if (map->dir == 'Z')
		parse_direction(map);
	return (OK);
}
