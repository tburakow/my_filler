/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:01:09 by tburakow          #+#    #+#             */
/*   Updated: 2022/04/13 12:01:23 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_lgt_uns(unsigned long long n)
{
	int	i;

	i = 0;
	if ((long long)n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static char	*popul_str_uns(char *str, int len, unsigned long long n)
{	
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = (n % 10 + '0');
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa_unsigned(unsigned long long n)
{
	char		*str;
	int			len;

	len = nbr_lgt_uns(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str = popul_str_uns(str, len, n);
	return (str);
}
