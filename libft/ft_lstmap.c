/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:51:58 by jwebber           #+#    #+#             */
/*   Updated: 2019/09/12 19:24:48 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;

	if (lst == NULL || f == NULL)
		return (NULL);
	ret = f(lst);
	if (ret == NULL)
		return (NULL);
	ret->next = ft_lstmap(lst->next, f);
	return (ret);
}
