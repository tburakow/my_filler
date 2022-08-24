/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:51:30 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/24 12:57:46 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		skip_line(void)
{
	fprint_string("start of skip_line");
	char	*skip_line;
	int		ret;
	
	ret = get_next_line(STDIN, &skip_line);
	if (ret < 0)
		return (KO);
	fprint_string(skip_line);
	//ft_strdel(&skip_line);
	return (OK);
}