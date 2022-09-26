/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:56:34 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/26 21:00:34 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	add_to_line_two(char **line, char **arr, const int fd)
{
	*line = ft_strdup(arr[fd]);
	ft_strdel(&arr[fd]);
	if (!line)
		return (0);
	return (1);
}

int	add_to_line(char **line, char **arr, const int fd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (arr[fd][i] != '\n' && arr[fd][i] != '\0')
		i++;
	if (arr[fd][i] == '\n')
	{
		tmp = ft_strdup(&(arr[fd][i + 1]));
		if (!tmp)
			return (-1);
		arr[fd][i] = '\0';
		*line = ft_strdup(arr[fd]);
		if (!line)
			return (-1);
		free(arr[fd]);
		arr[fd] = tmp;
		if (arr[fd][0] == '\0')
			ft_strdel(&arr[fd]);
	}
	else if (!add_to_line_two(line, arr, fd))
		return (-1);
	return (1);
}

int	read_and_join(char **arr, const int fd)
{
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	ret = read(fd, buf, BUFF_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (arr[fd] == NULL)
			arr[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(arr[fd], buf);
			free(arr[fd]);
			arr[fd] = tmp;
		}
		if (ft_strchr(arr[fd], '\n') != NULL)
			break ;
		ret = read(fd, buf, BUFF_SIZE);
	}
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*arr[FD_SIZE + 1];

	if (fd < 0 || line == NULL || fd > FD_SIZE)
		return (-1);
	ret = read_and_join(arr, fd);
	if (ret < 0)
		return (-1);
	if (ret == 0 && arr[fd] == NULL)
		return (0);
	return (add_to_line(line, arr, fd));
}
