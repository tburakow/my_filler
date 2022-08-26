/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twod_vector_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:08:47 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/26 11:54:59 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function calculates the length of a vector between two coordinates in a
 2d-array. it return the answer as a float. */
float	twod_vector_length(int y_1, int x_1, int y_2, int x_2)
{
	int		ret;
	int		h;
	int		w;

	h = y_2 - y_1;
	w = x_2 - x_1;
	if (h < 0)
		h *= -1;
	if (w < 0)
		w *= -1;
	ret = (h * h) + (w * w);
	return (square_root(ret, 5));
}
