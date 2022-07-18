/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:01:09 by tburakow          #+#    #+#             */
/*   Updated: 2022/05/09 11:53:39 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_lgt_uns(unsigned long long n, unsigned long long base)
{
	int	i;

	i = 0;
	if ((long long)n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > (base - 1))
	{
		n = n / base;
		i++;
	}
	i++;
	return (i);
}

static char	*popul_str_uns(char *str, int len, unsigned long long n, \
unsigned long long base)
{	
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = (n % base + '0');
		n = n / base;
	}
	return (str);
}

char	*ft_itoa_base(unsigned long long n, unsigned long long base)
{
	char		*str;
	int			len;

	len = nbr_lgt_uns(n, base);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str = popul_str_uns(str, len, n, base);
	return (str);
}
