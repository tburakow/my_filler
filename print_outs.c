/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_outs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:48:47 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/26 19:26:27 by tburakow         ###   ########.fr       */
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

void	fprint_out_heat(t_heat *heat, char *s)
{
	FILE 	*fp;
	int 	i;
	int		j;

	i = 0;
	j = 0;
	fp = fopen("heats", "a");
	fprintf(fp, "----------------------------------------------\n");
	fprintf(fp, "\n%s\n\n", s);
	fprintf(fp, "----------------------------------------------\n");
	if (heat->array)	
		while (i < heat->size.h)
		{
			j = 0;
			while (j < heat->size.w)
			{
				if (heat->array[i][j])
					fprintf(fp, "%d, ", heat->array[i][j]);
				j++;
			}
			fprintf(fp, "\n");
			i++;
		}
	fprintf(fp, "\n----------------------------------------------\n");
	i = 0;
	if (heat->map_copy)	
		while (i < heat->size.h)
		{
			if (heat->map_copy[i])
				fprintf(fp, "%s\n", heat->map_copy[i]);
			i++;
		}
	fprintf(fp, "\n----------------------------------------------\n");
	if (heat->size.h && heat->size.w)
		fprintf(fp, "heat h : %d, heat : %d\n\n", heat->size.h, heat->size.w);
	if (heat->heat)
		fprintf(fp, "heat is : %d", heat->heat);
	if (heat->orig.y && heat->orig.x)
		fprintf(fp, "heat orig. y : %d, heat orig. x : %d\n\n", heat->orig.y, heat->orig.x);
	fclose(fp);
}