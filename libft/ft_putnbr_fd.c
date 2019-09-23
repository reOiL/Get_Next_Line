/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:59:25 by jwebber           #+#    #+#             */
/*   Updated: 2019/09/12 17:16:25 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long ll;

	ll = n;
	if (ll == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (ll < 0)
	{
		ft_putchar_fd('-', fd);
		ll *= -1;
	}
	if (ll / 10 != 0)
		ft_putnbr_fd(ll / 10, fd);
	ft_putchar_fd('0' + ll % 10, fd);
}
