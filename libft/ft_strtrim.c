/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 10:14:37 by jwebber           #+#    #+#             */
/*   Updated: 2019/09/12 18:53:56 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_needtrim(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static int	ft_trim_start(char const *s)
{
	int		a;

	if (s == NULL)
		return (0);
	a = 0;
	while (ft_needtrim(s[a]) && s[a] != '\0')
		a++;
	return (a);
}

static int	ft_trim_end(char const *s, size_t len)
{
	int	a;

	if (s == NULL)
		return (0);
	a = 0;
	while (len != 0 && ft_needtrim(s[len - 1]))
	{
		a++;
		len--;
	}
	return (a);
}

char		*ft_strtrim(char const *s)
{
	size_t		len;
	char		*ret;
	size_t		start;
	size_t		end;
	size_t		i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	start = ft_trim_start(s);
	if (start != len)
		end = ft_trim_end(s, len);
	else
		end = 0;
	if (!(ret = ft_strnew(len - (start + end))))
		return (NULL);
	i = 0;
	while (start < len - end)
	{
		ret[i] = s[start];
		start++;
		i++;
	}
	return (ret);
}
