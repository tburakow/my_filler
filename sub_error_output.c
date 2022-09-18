/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_error_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:15:56 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/01 14:32:43 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* This function is used to print out error messages from outside the "main"
-function. */
int	sub_error_output(char *s)
{
	error_out(s);
	return (KO);
}
