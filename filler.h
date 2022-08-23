/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:04:16 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/23 14:26:23 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"
#include <stdio.h>

# define STDIN 0
# define OK 1
# define KO 0
# define MIN -1
# define ME 2
# define OPP 3

/* This struct holds the map and piece information, and assigns the correct sym-
bols for the players. */
typedef	struct	s_data
{
	int 	players_set;
	char	player;
	char 	opponent;
	char	**map;
	int 	map_w;
	int		map_h;
/* 	char **map;
	int piece_x;
	int piece_y;
	char **piece_fill; */
}				t_data;

typedef	struct	s_heat
{
	int		**array;
	int		w;
	int		h;
	int		heat;
	int 	orig_h;
	int 	orig_w;
	char	**map_copy;
}			t_heat;

typedef struct	s_coord
{
	int	h;
	int w;
}				t_coord;

typedef	struct	s_piece
{
	t_coord	whole;
	t_coord	top_left;
	t_coord right_bottom;
	char	**array;
	t_coord best;
	int		best_score;
}			t_piece;

/* in main.c - file */
int	determine_player(t_data **map_plr);
int	init(t_data **map_plr, t_heat **heatmap);

/* In play.c -File */
int	try_piece(t_data **map_plr, t_heat **heatmap, t_piece **piece);
int	play(t_data **map_plr, t_piece **piece, t_heat **heatmap);

/* in get_map.c - file */
int	get_map(t_data **map_plr);
int get_map_size(t_data **map_plr);
int fill_map(t_data **map_plr);

/* in the print_out.c -file */
void	print_out_map(t_data **map_plr);
void	print_out_piece(t_piece **piece);
void	print_out_heatmap(t_heat **heatmap);

/* in the skip_line.c -file */
void	skip_line(char **input);

/* in create_structs.c - file */
int create_map(t_data **map_plr);
int	create_piece(t_piece **piece);
int create_heatmap(t_heat **heatmap, t_data **map_plr);

/* in the get_piece.c -file */
int get_piece(t_piece **piece);
int get_piece_size(t_piece **piece);

/* in the error_output.c -file */
int	error_output(int type, char *msg);

/* in the get_heat.c -file */
int	get_heat(t_heat **heatmap, t_data **map_plr);
int	check_occup(char c, t_data **map_plr);
int	calculate_heat(t_heat **heatmap, t_data **map_plr, int h, int w);
void	parse_heat(t_data **map_plr, t_heat **heatmap, int h, int w);

/* in the vector.c file */
int		vector_calc(int h, int w);

/* in square_root.c -file */
float	square_root(int num, int dec);

#endif