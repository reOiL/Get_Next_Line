/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 11:30:49 by jwebber           #+#    #+#             */
/*   Updated: 2019/09/12 16:47:51 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_int_len(long long n)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 1)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	long long	nb;
	char		*ret;
	int			i;
	int			len;

	i = 0;
	nb = n;
	len = ft_int_len(nb);
	ret = ft_strnew(len);
	if (ret == NULL)
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		ret[i] = '-';
		i++;
		len--;
	}
	while (len >= i)
	{
		ret[len - (1 - i)] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	return (ret);
}
