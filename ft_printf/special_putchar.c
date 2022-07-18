/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_putchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:26:40 by tburakow          #+#    #+#             */
/*   Updated: 2022/04/13 14:49:18 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** used for printing out character in certain cases.
*/
void	special_putchar(char c, t_flags **flags)
{
	if (c != '\0')
	{
		(*flags)->output++;
		write(1, &c, 1);
	}
}
