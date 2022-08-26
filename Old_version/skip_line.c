/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:51:30 by tburakow          #+#    #+#             */
/*   Updated: 2022/08/24 14:14:42 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		skip_line(void)
{
	fprint_string("start of skip_line");
	char	*skip_line;
	int		ret;
	
	skip_line = NULL;
	ret = get_next_line(STDIN, &skip_line);
	fprint_int(ret);
	if (ret < 0)
		return (KO);
	fprint_string_2(skip_line, "inputs");
	if (skip_line)
		free(skip_line);
	return (OK);
}