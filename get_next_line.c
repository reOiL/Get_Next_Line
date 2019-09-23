/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 08:49:04 by jwebber           #+#    #+#             */
/*   Updated: 2019/09/23 16:26:00 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_strrealloc(char *a, char *b)
{
	char	*t;

	if (a == NULL && b != NULL)
		t = ft_strjoin("", b);
	else if (b == NULL && a != NULL)
		t = ft_strjoin(a, "");
	else
		t = ft_strjoin(a, b);
	return (t);
}

static char	*ft_strrealloc_fo(char **a, char *b)
{
	char *f;

	if (!a)
		return (NULL);
	f = ft_strrealloc(*a, b);
	ft_strdel(a);
	return (f);
}

static char	*ft_strrealloc_ff(char **a, char **b)
{
	char *f;

	if (!a || !b)
		return (NULL);
	f = ft_strrealloc(*a, *b);
	ft_strdel(a);
	ft_strdel(b);
	return (f);
}

int			get_next_line_sub(const int fd, char **line, char **temp)
{
	static char *prevision[256];
	char		*new_line_pos;

	if (prevision[fd])
		*temp = ft_strrealloc_ff(&prevision[fd], &(*temp));
	if (*temp == NULL)
		return (0);
	new_line_pos = ft_strchr(*temp, '\n');
	if (new_line_pos && !(new_line_pos[0] = 0) && new_line_pos[1] != '\0')
		prevision[fd] = ft_strdup(new_line_pos + 1);
	(*line) = ft_strdup(*temp);
	ft_strdel(temp);
	return ((*line) != NULL);
}

int			get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	int			rs;
	char		*temp;

	if (line == NULL || fd < 0 || fd > 256)
		return (-1);
	temp = NULL;
	while ((rs = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[rs] = '\0';
		if (!(temp = ft_strrealloc_fo(&temp, buffer)))
			return (-1);
		if ((ft_strchr(buffer, '\n')))
			break ;
	}
	if (rs < 0)
		return (-1);
	return (get_next_line_sub(fd, line, &temp));
}
