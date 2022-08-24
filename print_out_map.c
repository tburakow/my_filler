/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:28:55 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/24 16:12:50 by tburakow         ###   ########.fr       */
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

void	dprint_out_map(t_data **map_plr)
{
	int i;

	i = 0;
	while (i < (*map_plr)->map_h)
	{
		dprintf(2, "%s\n", (*map_plr)->map[i]);
		i++;
	}
}

void	fprint_out_map(t_data **map_plr)
{
	FILE 	*fp;
	int 	i;

	i = 0;
	fp = fopen("maps_read", "a");
	fprintf(fp, "\n---- START OF NEW MAP ----\n\n");
	while (i < (*map_plr)->map_h)
	{
		fprintf(fp, "%s\n", (*map_plr)->map[i]);
		i++;
	}
	fclose(fp);
}

void	fprint_out_piece(t_piece **piece)
{
	FILE 	*fp;
	int 	i;

	i = 0;
	fp = fopen("maps_read", "a");
	fprintf(fp, "\n---- START OF NEW PIECE ----\n\n");
	while (i < (*piece)->whole.h)
	{
		fprintf(fp, "%s\n", (*piece)->array[i]);
		i++;
	}
	fclose(fp);
}

void fprint_string(char *message)
{
	FILE 	*fp;
	int 	i;

	i = 0;
	fp = fopen("msg", "a");
	fprintf(fp, "%s\n", message);
	fclose(fp);
}

void fprint_string_2(char *message, char *filename)
{
	FILE 	*fp;
	int 	i;

	i = 0;
	fp = fopen(filename, "a");
	fprintf(fp, "%s\n", message);
	fclose(fp);
}

void fprint_int(int message)
{
	FILE 	*fp;
	int 	i;

	i = 0;
	fp = fopen("msg", "a");
	fprintf(fp, "%d\n", message);
	fclose(fp);
}

void	print_out_piece(t_piece **piece)
{
	int i;

	i = 0;
	while (i < (*piece)->whole.h)
	{
		ft_printf("%s\n", (*piece)->array[i]);
		i++;
	}
}

void	print_out_heatmap(t_heat **heatmap)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < (*heatmap)->h)
	{
		j = 0;
		while (j < (*heatmap)->w)
		{
			ft_printf("%i ", (*heatmap)->array[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}