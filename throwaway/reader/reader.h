/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:04:16 by tburakow          #+#    #+#             */
/*   Updated: 2022/07/21 14:03:23 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/libft/libft.h"

/* This struct holds the map and piece information, and assigns the correct sym-
bols for the players. */
typedef struct s_data
{
	int player;
/* 	int	map_x;
	int map_y;
	char **map;
	int piece_x;
	int piece_y;
	char **piece_fill; */
}	t_data;

/* in main.c - file */
int	determine_player(char *name);
int	init_struct(t_data **map_plr);

#endif