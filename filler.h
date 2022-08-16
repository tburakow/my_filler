/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:04:16 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/11 14:52:50 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"

# define STDIN 0
# define OK 1
# define KO 0

/* This struct holds the map and piece information, and assigns the correct sym-
bols for the players. */
typedef	struct	s_data
{
	int 	players_set;
	char	player;
	char 	opponent;
	t_array map;
	int 	map_w;
	int		map_h;
/* 	char **map;
	int piece_x;
	int piece_y;
	char **piece_fill; */
	}			t_data;

typedef struct  s_array
{
	char **array;
}				t_array;



/* in main.c - file */
int	determine_player(t_data **map_plr);
int	init_struct(t_data **map_plr);

/* in get_map.c -file */
int	get_map(t_data **map_plr);

#endif