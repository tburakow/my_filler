/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:22:32 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/23 14:28:32 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		set_piece_limits(t_piece **piece)
{
	int 	j;
	int		k;
	
	j = 0;
	k = 0;
	while(j < (*piece)->whole.h)
	{
		k = 0;
		while (k < (*piece)->whole.w)
		{
			if ((*piece)->array[j][k] == '*')
			{
				if (j < (*piece)->top_left.h)
					(*piece)->top_left.h = j;
				if (k < (*piece)->top_left.w)
					(*piece)->top_left.w = k;
				if (k > (*piece)->right_bottom.h)
					(*piece)->right_bottom.h = k;
				if (j > (*piece)->right_bottom.w)
					(*piece)->right_bottom.w = j;
			}
			k++;
		}
		j++;
	}
	return (0);
}

int get_piece_size(t_piece **piece)
{
	char	*line;
	int		i;

	i = 0;
	if (get_next_line(STDIN, &line) <= 0)
		return(error_output(KO, "failed to read line for piece size."));
	printf("!!!!%s\n", line);
	if (ft_strstr(line, "Piece") != NULL)
	{
		while(line[i])
		{
			if(ft_isdigit(line[i]))
			{
				if(!(*piece)->whole.h)
					(*piece)->whole.h = ft_atoi(&line[i]);
				else
					(*piece)->whole.w = ft_atoi(&line[i]);
				while (ft_isdigit(line[i]))
					i++;
			}
			i++;
		}
	}
	printf("piece h: %d\n", (*piece)->whole.h);
	printf("piece w: %d\n", (*piece)->whole.w);
	//ft_printf("Map size is ; width : %i. height : %i.\n", (*map_plr)->map_w, (*map_plr)->map_h);
	ft_strdel(&line);
	return (OK);
}

int get_piece(t_piece **piece)
{
	char	*line;
	int		i;

	i = 0;
	printf("Helloo from get_piece! START!\n");
	if (!get_piece_size(piece))
		return(error_output(KO, "error : failed to get piece size"));
	(*piece)->array = (char **)malloc(sizeof(char *) * (*piece)->whole.h);
	while (i < (*piece)->whole.h)
	{
		if (get_next_line(STDIN, &line) <= 0)
			return(error_output(KO, "piece line reading failed."));
		(*piece)->array[i] = ft_strdup(line);
		printf("1\n");
		ft_strdel(&line);
		printf("2\n");
		i++;
	}
	if (!set_piece_limits(piece))
		return(error_output(KO, "Setting of piece limits failed"));
	printf("Helloo from get_piece! END\n");
	return (OK);
}