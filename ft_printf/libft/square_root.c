/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_root.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:30:55 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/26 09:48:13 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function calculates the fractional value for the
square_root -function */
static float	fractions(float output, int num, int dec)
{
	float	increment;
	int		i;

	i = 0;
	increment = 0.1;
	while (i < dec)
	{
		while (output * output <= num)
		{
			output += increment;
		}
		output = output - increment;
		increment = increment / 10;
		i++;
	}
	return (output);
}

/* A function to calculate the square root of a number, the second int 
gives the number of decimals.*/
float	square_root(int num, int dec)
{
	int		start;
	int		end;
	int		mid;
	float	output;

	start = 0;
	mid = 0;
	end = num;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (mid * mid == num)
		{
			output = mid;
			break ;
		}
		if (mid * mid < num)
		{
			output = start;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	return (fractions(output, num, dec));
}
