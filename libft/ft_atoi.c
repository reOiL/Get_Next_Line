/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:37:37 by jwebber           #+#    #+#             */
/*   Updated: 2019/09/12 16:44:37 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			minus;
	long int	val;
	int			i;

	minus = 1;
	i = 0;
	val = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((val * 10) + (str[i] - '0') < val)
			return (minus == 1 ? -1 : 0);
		val = (val * 10) + (str[i] - '0');
		i++;
	}
	return (val * minus);
}
