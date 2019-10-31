/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:19:05 by gbarach-          #+#    #+#             */
/*   Updated: 2019/01/14 20:20:16 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_eof(char **line, char **stock)
{
	(*line) = ft_strsub(*stock, 0, (ft_strlen(*stock)));
	ft_strdel(stock);
	return (*line ? 1 : -1);
}

int	ft_read_and_sort(char **line, int fd, char **stock)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while (!(ft_strchr(*stock, '\n')))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 1)
			return (ret);
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(*stock, buf)))
			return (-1);
		ft_strdel(stock);
		*stock = tmp;
		if (ret < BUFF_SIZE && !ft_strchr(*stock, '\n'))
			return (ft_eof(line, stock));
	}
	(*line) = ft_strsub(*stock, 0, ft_strnlen(*stock, '\n'));
	if (!(tmp = ft_strdup(ft_strchr(*stock, '\n') + 1)))
		return (-1);
	free(*stock);
	*stock = tmp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char *stock = NULL;
	int			ret;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (!stock && !(stock = ft_strnew(0)))
		return (-1);
	*line = NULL;
	ret = ft_read_and_sort(line, fd, &stock);
	if (stock && ret < 1)
		ft_strdel(&stock);
	return (ret);
}
