/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:48:24 by jwebber           #+#    #+#             */
/*   Updated: 2019/09/12 17:09:46 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char	*usrc;
	unsigned char		*udst;
	unsigned char		uc;

	i = 0;
	uc = c;
	usrc = src;
	udst = dst;
	while (i < n)
	{
		udst[i] = usrc[i];
		if (udst[i] == uc)
			return (udst + i + 1);
		i++;
	}
	return (NULL);
}
