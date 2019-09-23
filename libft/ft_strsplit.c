/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 10:56:29 by jwebber           #+#    #+#             */
/*   Updated: 2019/09/12 19:01:39 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		word_len;
	int		i;

	if (!s || !(ret = (char **)ft_memalloc(sizeof(char *) * ft_wcount(s, c))))
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			word_len = 0;
			while (s[word_len] != c && s[word_len] != '\0')
				word_len++;
			if (!(ret[i] = ft_strncpy(ft_strnew(word_len), s, word_len)))
				return (ft_remove_sstr(&ret));
			s += word_len;
			i++;
		}
		else
			s++;
	}
	ret[i] = NULL;
	return (ret);
}
