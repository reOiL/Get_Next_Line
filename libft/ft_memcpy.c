/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:17:08 by jwebber           #+#    #+#             */
/*   Updated: 2019/09/12 17:12:22 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL && n != 0)
		return (NULL);
	while (i < n)
	{
		((char *)dst)[i] = ((const char*)src)[i];
		i++;
	}
	return (dst);
}
