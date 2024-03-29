/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:04:16 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/26 22:25:56 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../ft_printf/libft/libft.h"
# include "../ft_printf/ft_printf.h"

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
}				t_map;

typedef struct s_heat
{
	int			**array;
	t_size		size;
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
int		fill_map(t_map *map, int i, int j);
void	skip_line(void);
void	parse_map_size(t_map *map, char *line);

/* in the parse_direction.c -file  */
void	parse_direction(t_map *map);
void	*handle_null(void *input, char *s);
void	run_adjustments(t_heat *heat, t_map *map);

/* In main.c -file */
int		init(t_map *map, t_heat *heat, t_piece *piece);
void	write_out(int y, int x);
void	free_structs(t_map *map, t_heat *heat, t_piece *piece);

/* In heat_extras.c -file */
int		adjust_to_map(t_heat *heat, t_map *map, int y, int x);
int		check_heat_diag(t_heat *heat, t_coords *cell, int value);
int		check_heat_axial(t_heat *heat, t_coords *cell, int value);
int		adjust_to_direction(t_map *map, int y, int x);

/* In the heat_checks_one.c -file */
int		check_up(t_heat *heat, t_coords *cell, int value);
int		check_left(t_heat *heat, t_coords *cell, int value);
int		check_down(t_heat *heat, t_coords *cell, int value);
int		check_right(t_heat *heat, t_coords *cell, int value);

/* In the heat_checks_two.c -file */
int		check_up_left(t_heat *heat, t_coords *cell, int value);
int		check_down_left(t_heat *heat, t_coords *cell, int value);
int		check_up_right(t_heat *heat, t_coords *cell, int value);
int		check_down_right(t_heat *heat, t_coords *cell, int value);

/* In the get_heat.c -file */
int		get_heat(t_heat *heat, t_map *map);
int		heat_setup(t_heat *heat, t_map *map);
void	update_on_players(t_heat *heat, t_map *map, int i);
int		scan_adjacent_cells(t_heat *heat, t_coords *cell, int value);
int		heat_update(t_heat *heat, int target, int value);

/* in the get_piece.c -file */
int		get_piece(t_piece *piece);
int		get_piece_size(t_piece *piece);
int		get_piece_actual(t_piece *piece);

/* In the play.c -file */
int		play(t_map *map, t_heat *heat, t_piece *piece);
int		try_piece(t_map *map, t_heat *heat, t_piece *piece, t_coords *current);
int		validate_place(t_map *map, t_piece *piece, t_coords *current);
int		place_piece(t_map *map, t_heat *heat, t_piece *piece);
void	score_piece(t_heat *heat, t_piece *piece, t_coords *curr);

/* In the hits_and_crashes.c -file */
int		hits_crashes(t_map *map, t_coords *curr, t_coords *spot);

/* In the free_s.c -file */
void	free_map(t_map *map);
void	free_heat(t_heat *heat);
void	free_piece(t_piece *piece);
#endif