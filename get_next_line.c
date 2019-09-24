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

static void			ft_del(const int fd, t_list **lst)
{
	t_file	*ff;
	t_list	*p;

	if (lst == NULL || *lst == NULL)
		return ;
	if (!(ff = (*lst)->content))
		return ;
	if (ff->fd == fd)
	{
		p = *lst;
		*lst = p->next;
		ft_strdel(&ff->fdata);
		ft_memdel((void **)&ff);
		ft_memdel((void **)&p);
		return ;
	}
	ft_del(fd, &(*lst)->next);
}

static t_file		*f_find(const int fd, t_list **lst)
{
	t_file	*f;

	if (lst == NULL)
		return (NULL);
	if (*lst == NULL)
	{
		*lst = ft_lstnew(NULL, 0);
		if (*lst == NULL)
			return (NULL);
		(*lst)->content_size = sizeof(t_file);
		(*lst)->content = ft_memalloc(sizeof(t_file));
		if ((*lst)->content == NULL)
		{
			ft_memdel((void **)lst);
			return (NULL);
		}
		f = (t_file *)(*lst)->content;
		f->fd = fd;
		return (f);
	}
	f = (t_file*)((*lst)->content);
	if (f && f->fd == fd)
		return (f);
	return (f_find(fd, &((*lst)->next)));
}

int					get_next_line_sub(t_file *ff, char **line,
		const int fd, t_list **l)
{
	char		*new_line_pos;
	char		*temp;

	if (ff == NULL || ff->fdata == NULL)
		return (0);
	temp = ft_strdup(ff->fdata);
	ft_strdel(&ff->fdata);
	new_line_pos = ft_strchr(temp, '\n');
	(*line) = 0;
	if (new_line_pos)
	{
		new_line_pos[0] = 0;
		if (new_line_pos[1] != '\0')
			ff->fdata = ft_strdup(new_line_pos + 1);
	}
	(*line) = ft_strdup(temp);
	ft_strdel(&temp);
	if (!ff->fdata)
		ft_del(fd, l);
	return ((*line) != NULL);
}

int					get_next_line(const int fd, char **line)
{
	char				buffer[BUFF_SIZE + 1];
	int					rs;
	char				*temp;
	static t_list		*lst;
	t_file				*ff;

	if ((line == NULL || fd < 0) || !(ff = f_find(fd, &lst)))
		return (-1);
	while ((rs = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[rs] = '\0';
		temp = ff->fdata;
		ff->fdata = ft_strjoin((ff->fdata == NULL ? "" : ff->fdata), buffer);
		ft_strdel(&temp);
		if (!ff->fdata)
			return (-1);
		if ((ft_strchr(buffer, '\n')))
			break ;
	}
	if (rs < 0)
	{
		ft_del(fd, &lst);
		return (-1);
	}
	return (get_next_line_sub(ff, line, fd, &lst));
}
