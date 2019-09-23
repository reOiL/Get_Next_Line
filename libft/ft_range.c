/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:10:56 by jwebber           #+#    #+#             */
/*   Updated: 2019/09/12 19:38:48 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int min, int max)
{
	long long	size;
	int			*arr;
	long long	i;

	if (min >= max)
		return (NULL);
	size = (long long)max - (long long)min;
	if (size <= 0)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (((long long)min + i) < (long long)max)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
