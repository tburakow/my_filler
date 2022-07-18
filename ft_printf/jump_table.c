/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:37:25 by tburakow          #+#    #+#             */
/*   Updated: 2022/04/21 15:31:59 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Initializes the format jump table and determines which format to use.
*/
void	jump_table(size_t i, t_flags **flags)
{
	t_formats	*jump[10];

	jump[0] = signed_int;
	jump[1] = signed_int;
	jump[2] = unsigned_octal;
	jump[3] = unsigned_dec;
	jump[4] = unsigned_hex;
	jump[5] = unsigned_hex;
	jump[6] = float_dec_point;
	jump[7] = character;
	jump[8] = string;
	jump[9] = pointer;
	jump[i](flags);
}
