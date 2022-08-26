/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:04:16 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/26 15:17:29 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <string.h>

# define STDIN 0
# define KO 0
# define OK 1

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

typedef	struct s_map
{
	int			players_set;
	char		*player;
	char		*opponent;
	char		**array;
	t_size	 	size;
}				t_map;

typedef struct s_heat
{
	int			**map;
	t_size		size;
	int			heat;
	t_coords	orig;
}				t_heat;

typedef struct s_piece
{
	t_coords	orig;
	t_coords	start;
	t_coords	end;
	t_size		active;
	t_coords	best;
	char		**array;
	int			best_score;
}				t_piece;

/* in the sub_error_output.c -file */
int		sub_error_output(char *s);

/* in the get_player.c -file */
int		get_player(t_map *map);

/* In the get_map.c -file. */
int		get_map_size(t_map *map);
int		get_map(t_map *map);

/* In the print_outs.c -file */
void	fprint_out_map(t_map *map, char *s);
void	fprint_out_int(int i, char *s);

/* In main.c -file */
int	init(t_map *map, t_heat *heat, t_piece *piece);

#endif