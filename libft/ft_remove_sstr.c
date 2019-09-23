/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_sstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:28:51 by jwebber           #+#    #+#             */
/*   Updated: 2019/09/12 17:42:50 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_remove_sstr(char ***s)
{
	int	i;

	if (s == NULL || *s == NULL || **s == NULL)
		return (NULL);
	i = 0;
	while ((*s)[i] != NULL)
	{
		ft_strdel(&(*s)[i]);
		i++;
	}
	ft_memdel((void **)(*s));
	*s = NULL;
	return (*s);
}
