/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:48:15 by iha               #+#    #+#             */
/*   Updated: 2021/07/21 13:48:18 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(char *str)
{
	int	cur;

	cur = 0;
	if (str == NULL)
		return (-1);
	while (str[cur])
	{
		if (str[cur] == '\n')
			return (cur);
		cur++;
	}
	return (-1);
}

char	*cal_next_line(char **str, int endidx, int fd)
{
	char	*next_line;
	char	*backup;
	int		len;
	int		idx;

	idx = -1;
	len = ft_strlen(str[fd]) - endidx;
	next_line = (char *)malloc(sizeof(char) * (endidx + 1));
	if (next_line == NULL)
		return (NULL);
	backup = (char *)malloc(sizeof(char) * (len + 1));
	if (backup == NULL)
	{
		free(next_line);
		return (NULL);
	}
	while (++idx < endidx)
		next_line[idx] = str[fd][idx];
	next_line[idx] = '\0';
	idx = -1;
	while (++idx <= len)
		backup[idx] = str[fd][endidx + 1 + idx];
	free(*str);
	str[fd] = backup;
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*backup[OPEN_MAX];
	char		*next_line;
	int			rdsize;
	int			endidx;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	endidx = is_newline(backup[fd]);
	rdsize = BUFFER_SIZE;
	while (endidx == -1 && rdsize == BUFFER_SIZE)
	{
		rdsize = read(fd, buf, BUFFER_SIZE);
		buf[rdsize] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		endidx = is_newline(backup[fd]);
	}
	if (rdsize != BUFFER_SIZE && endidx == -1)
		endidx = ft_strlen(backup[fd]);
	if (endidx == 0)
		return (NULL);
	next_line = cal_next_line(backup, endidx, fd);
	if (next_line == NULL)
		return (NULL);
	return (next_line);
}
