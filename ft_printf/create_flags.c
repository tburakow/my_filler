/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:46:16 by tburakow          #+#    #+#             */
/*   Updated: 2022/04/13 13:53:28 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Used to create the "flags" -struct.
** The struct includes all the flags for printf, and some other variables
** needed in the propere handling of input.
*/
int	create_flags(t_flags **flags)
{
	*flags = (t_flags *)ft_memalloc(sizeof(t_flags));
	if (*flags == NULL)
		return (0);
	(*flags)->l = 0;
	(*flags)->h = 0;
	(*flags)->bigl = 0;
	(*flags)->zero = 0;
	(*flags)->hash = 0;
	(*flags)->minus = 0;
	(*flags)->plus = 0;
	(*flags)->width = 0;
	(*flags)->precision = 0;
	(*flags)->type = 0;
	(*flags)->neg = 0;
	(*flags)->empty_prec = 0;
	(*flags)->base_size = 8;
	(*flags)->output = 0;
	(*flags)->char_null = 0;
	(*flags)->f_check = 0;
	(*flags)->checksum = 0;
	(*flags)->min_chars = 0;
	return (1);
}
