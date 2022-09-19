/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_outs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:48:47 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/19 20:19:46 by tburakow         ###   ########.fr       */
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
		fprintf(fp, "player : %c\n", map->player);
	if (map->opponent)
		fprintf(fp, "opponent : %c\n", map->opponent);
	if (map->array)
	{
		while (i < map->size.h)
		{
			if (map->array[i])
				fprintf(fp, "%s\n", (char *)map->array[i]);
			i++;
		}
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

void	fprint_out_piece(t_piece *piece, char *s)
{
	FILE 	*fp;
	int 	i;
	int		j;

	i = 0;
	j = 0;
	fp = fopen("pieces", "a");
	fprintf(fp, "----------------------------------------------\n");
	fprintf(fp, "\n%s\n\n", s);
	fprintf(fp, "----------------------------------------------\n");
	if (piece->array)
	{
		while (i < piece->size.h)
		{
			j = 0;
			while (j < piece->size.w)
			{
				if (piece->array[i][j])
					fprintf(fp, "%c ", piece->array[i][j]);
				j++;
			}
			fprintf(fp, "\n");
			i++;
		}
	}
	if (piece->best_score)
		fprintf(fp, "best_score is : %d\n", piece->best_score);
	if (piece->best.y && piece->best.x)
		fprintf(fp, "piece best y : %d, piece best x : %d\n\n", piece->best.y, piece->best.x);
	if (piece->start.y && piece->start.x)
		fprintf(fp, "piece start y : %d, piece start x : %d\n\n", piece->start.y, piece->start.x);
	if (piece->end.y && piece->end.x)
		fprintf(fp, "piece end y : %d, piece end x : %d\n\n", piece->start.y, piece->start.x);
	fclose(fp);
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
	{
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
	}
	i = 0;
	if (heat->map_copy)
	{
		while (i < heat->size.h)
		{
			fprintf(fp, "%s\n", heat->map_copy[i]);
			i++;
		}
	}
	fprintf(fp, "\n----------------------------------------------\n");
}