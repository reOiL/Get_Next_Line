/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:02:28 by jwebber           #+#    #+#             */
/*   Updated: 2019/09/12 19:04:47 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	temp;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str) - 1;
	i = 0;
	temp = 0;
	while (i != len)
	{
		temp = *(str + i);
		*(str + i) = *(str + len);
		*(str + len) = temp;
		i++;
		len--;
	}
	return (str);
}
