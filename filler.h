/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:04:16 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/19 12:00:29 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <string.h>
# include <stdio.h>

# define STDIN 0
# define KO 0
# define OK 1
# define MIN -1

typedef struct s_coords
{
	int		y;
	int		x;
}				t_coords;

typedef struct s_size
{
	int		h;
	int		w;
}				t_size;	

typedef struct s_map
{
	int			players_set;
	char		player;
	char		opponent;
	char		**array;
	t_size		size;
	char		dir;
	int			turn;
	t_coords	start;
	t_coords	end;
}				t_map;

typedef struct s_heat
{
	int			**array;
	t_size		size;
	int			heat;
}				t_heat;

typedef struct s_piece
{
	t_coords	start;
	t_coords	end;
	t_coords	best;
	t_size		size;
	char		**array;
	int			best_score;
}				t_piece;

/* in the sub_error_output.c -file */
int		sub_error_output(char *s);

/* in the get_player.c -file */
int		get_player(t_map *map);
void	switch_players(t_map *map);

/* In the get_map.c -file. */
int		get_map_size(t_map *map);
int		get_map(t_map *map);

/* in the parse_direction.c -file  */
void	parse_direction(t_map *map);
int		adjust_to_time(t_map *map, int y, int x);
void	adjust_to_size(t_heat *heat, t_map *map, int y, int x);

/* In main.c -file */
int		init(t_map *map, t_heat *heat, t_piece *piece);
void	write_out(int y, int x);
void	free_structs(t_map *map, t_heat *heat, t_piece *piece);
void	free_piece(t_piece *piece);

/* In heat_extras.c -file */
int		adjust_to_map(t_heat *heat, t_map *map, int y, int x);
int		check_heat_diag(t_heat *heat, t_map *map, t_coords *cell, int value);
int		check_heat_axial(t_heat *heat, t_map *map, t_coords *cell, int value);
int		adjust_to_direction(t_map *map, int y, int x);
void	force_to_edges(t_heat *heat, t_map *map, int y, int x);

/* In the heat_checks_one.c -file */
int		check_up(t_heat *heat, t_map *map, t_coords *cell, int value);
int		check_left(t_heat *heat, t_map *map, t_coords *cell, int value);
int		check_down(t_heat *heat, t_map *map, t_coords *cell, int value);
int		check_right(t_heat *heat, t_map *map, t_coords *cell, int value);

/* In the heat_checks_two.c -file */
int		check_up_left(t_heat *heat, t_map *map, t_coords *cell, int value);
int		check_down_left(t_heat *heat, t_map *map, t_coords *cell, int value);
int		check_up_right(t_heat *heat, t_map *map, t_coords *cell, int value);
int		check_down_right(t_heat *heat, t_map *map, t_coords *cell, int value);

/* In the print_outs.c -file */
void	fprint_out_map(t_map *map, char *s);
void	fprint_out_int(int i, char *s);
void	fprint_out_heat(t_heat *heat, char *s);
void	fprint_out_piece(t_piece *piece, char *s);

/* In the get_heat.c -file */
int		get_heat(t_heat *heat, t_map *map);
int		heat_setup(t_heat *heat, t_map *map);
int		calculate_heat(t_heat *heat, t_map *map, int y, int x);
int		set_heat_limit(t_map *map);
void	run_adjustments(t_heat *heat, t_map *map);

/* in the get_piece.c -file */
int		get_piece(t_piece *piece);
int		get_piece_size(t_piece *piece);
int		get_piece_actual(t_piece *piece);

/* In the play.c -file */
int		play(t_map *map, t_heat *heat, t_piece *piece);
int		try_piece(t_map *map, t_heat *heat, t_piece *piece, t_coords *current);
int		validate_place(t_map *map, t_piece *piece, t_coords *current);
int		place_piece(t_map *map, t_heat *heat, t_piece *piece);

/* In the hits_and_crashes.c -file */
int		hits_and_crashes(t_map *map, char s, t_coords *curr, t_coords *spot);
#endif