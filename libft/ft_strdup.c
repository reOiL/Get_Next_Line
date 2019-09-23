/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:02:04 by jwebber           #+#    #+#             */
/*   Updated: 2019/09/12 17:20:57 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*n_str;
	int		i;

	i = 0;
	n_str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!n_str)
		return (NULL);
	while (src[i] != '\0')
	{
		n_str[i] = src[i];
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
