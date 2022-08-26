/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:08:47 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/26 19:37:30 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function calculates the length of a vector between two coordinates in a
 2d-array. it return the answer as a float. */
float	simple_vector_length(int y, int x)
{
	int		ret;

	if (y < 0)
		y *= -1;
	if (x < 0)
		x *= -1;
	ret = (y * y) + (x * x);
	return (square_root(ret, 5));
}
