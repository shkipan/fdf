/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:06:01 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/06 10:59:17 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count(const char *s, char c)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			k++;
		while (s[i] != c && s[i])
			i++;
	}
	return (k);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**res;
	int		count;
	int		size;
	int		j;

	count = ft_count(s, c);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	j = 0;
	while (j < count)
	{
		while (*s == c)
			s++;
		size = 0;
		while (*(s + size) != c && *(s + size))
			size++;
		res[j] = (char *)malloc(sizeof(char) * (size + 1));
		res[j] = ft_strncpy(res[j], s, size);
		j++;
		s += size + 1;
	}
	res[count] = NULL;
	return (res);
}
