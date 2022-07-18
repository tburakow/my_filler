/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_ascii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:45:38 by tburakow          #+#    #+#             */
/*   Updated: 2022/04/13 14:53:40 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Adds the fractions into the float after exponent and mantissa.
*/
char	*add_fractions(char *temp, long double mant, t_flags **flags)
{
	unsigned int	start;
	unsigned int	i;
	char			*str;

	str = ft_strnew(ft_strlen(temp) + (*flags)->precision + 1 + 1);
	if (!str)
		return (NULL);
	start = ft_strlen(temp);
	i = 0;
	while (i < start)
	{
		str[i] = temp[i];
		i++;
	}
	str[i++] = '.';
	while (i - start <= (*flags)->precision)
	{
		mant = mant * 10;
		str[i] = (intmax_t)mant + '0';
		mant = mant - (intmax_t)mant;
		i++;
	}
	return (str);
}

/*
** converts the long double "number" into a float (in string form)
*/
char	*to_ascii(long double number, t_flags **flags)
{
	char		*final;
	char		*temp;
	intmax_t	exp;
	long double	mant;

	exp = (intmax_t)number;
	temp = ft_itoa(exp);
	mant = number - (long double)exp;
	if ((*flags)->precision == 0)
	{
		if ((*flags)->hash == 1)
		{
			final = ft_strjoin(temp, ".");
			ft_strdel(&temp);
			return (final);
		}
		return (temp);
	}
	final = add_fractions(temp, mant, flags);
	ft_strdel(&temp);
	return (final);
}
