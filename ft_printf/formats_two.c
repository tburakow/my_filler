/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:44:05 by tburakow          #+#    #+#             */
/*   Updated: 2022/04/13 14:38:36 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Handles the input for format type "f"
*/
void	float_dec_point(t_flags **flags)
{
	long double	number;
	int			x;

	number = float_input_type(flags);
	x = infinity(number, flags);
	if (x != 0)
	{
		if (x == 2)
			float_mod("nan", flags);
		else
			float_mod("inf", flags);
	}
	else
		float_dec_point_two(number, flags);
}

/*
** Handles the input for format type "c"
*/
void	character(t_flags **flags)
{
	int		character;

	character = va_arg((*flags)->arg, int);
	character_mod(flags, character);
}

/*
** Handles the input for format type "s"
*/
void	string(t_flags **flags)
{
	char	*string;

	string = va_arg((*flags)->arg, char *);
	if (string == NULL)
		apply_flags("(null)", flags);
	else
		apply_flags(string, flags);
}

/*
** Handles the input for format type "p"
*/
void	pointer(t_flags **flags)
{
	unsigned long	pointer;

	pointer = va_arg((*flags)->arg, unsigned long);
	(*flags)->base_size = 16;
	if (pointer == 0)
		zero_pointer(flags);
	else
		non_zero_pointer(pointer, flags);
}

/*
** Handles the input for format type "%"
*/
void	percent(t_flags **flags)
{
	apply_flags("%", flags);
}
