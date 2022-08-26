/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_outs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:48:47 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/26 15:19:13 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* This functions prints out the current values of the struct "map", and
a message that gives the function to which this state corresponds. */
void	fprint_out_map(t_map *map, char *s)
{
	FILE 	*fp;
	int 	i;

	i = 0;
	fp = fopen("maps", "a");
	fprintf(fp, "----------------------------------------------\n");
	fprintf(fp, "\n%s\n\n", s);
	fprintf(fp, "----------------------------------------------\n");
	if (map->player)
		fprintf(fp, "player : %s\n", map->player);
	if (map->opponent)
		fprintf(fp, "opponent : %s\n", map->opponent);
	if (map->array)	
		while (i < map->size.h)
		{
			if (map->array[i])
				fprintf(fp, "%s\n", (char *)map->array[i]);
			i++;
		}
	if (map->size.h && map->size.w)
		fprintf(fp, "map h : %d, w : %d\n\n", map->size.h, map->size.w);
	fclose(fp);
}

void	fprint_out_int(int i, char *s)
{
	FILE	*fp;
	
	fp = fopen("misc", "a");
	fprintf(fp, "%s is : %d\n", s, i);
}