/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:40:40 by tburakow          #+#    #+#             */
/*   Updated: 2022/04/21 15:49:47 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** This function is used for printing error outputs into standard
** output
*/
int	error_output(char *mess)
{
	ft_putstr(mess);
	return (1);
}

/*
** Determines the miinimum amount of characters to be printed out
** Used in some cases when padding to right.
*/
static void	min_chars(t_flags **flags)
{
	int	count;

	count = (*flags)->width;
	(*flags)->min_chars = count;
}

/*
** This function determines the format for the current argument
** by comparing it's format specifier to a list of specifiers,
** after which it calls the format function with the 
** index of the correct type and returns the result of formatting.
*/
static void	determine_format(char c, t_flags **flags)
{
	char	*str;
	size_t	i;

	i = 0;
	str = "diouxXfcsp%";
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			min_chars(flags);
			if (c == '%')
				percent(flags);
			else
			{
				if (check_for_char((*flags)->type, "diouxX") == 1 \
				&& (*flags)->f_check == 1)
					(*flags)->zero = 0;
				jump_table(i, flags);
			}
		}
		i++;
	}
}

/* 
** Parses through the format string, determining all flags and 
** format types present.
*/
static void	parse_format(char *format, t_flags **flags)
{
	int	jmax;
	int	j;

	j = 0;
	jmax = ft_strlen(format);
	while (j < jmax)
	{
		reset_flags(flags);
		while (format[j] != '%' && j < jmax)
			special_putchar(format[j++], flags);
		if (j < jmax)
		{
			j = ft_raise_flags((char *)format, j, flags);
			determine_format(format[j], flags);
		}
		j++;
	}
}

/*
** My recoded version of the printf -function.
*/
int	ft_printf(const char *format, ...)
{
	t_flags		*flags;
	int			ret;

	ret = 0;
	if (create_flags(&flags) == 0)
		return (error_output("error: flags allocation failed."));
	va_start(flags->arg, format);
	if (format[0] == '%' && format[1] == '\0')
		return (0);
	parse_format((char *)format, &flags);
	va_end(flags->arg);
	ret = flags->output;
	free(flags);
	return (ret);
}
