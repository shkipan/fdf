/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 14:58:08 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/12 14:11:57 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_hex(char *s)
{
	int		len;
	int		res;
	int		ex;

	res = 0;
	ex = 1;
	len = ft_strlen(s) - 1;
	while (s[len] != 'x')
	{
		if (s[len] <= 'F' && s[len] >= 'A')
			res += ex * (s[len] - 'A' + 10);
		else if (s[len] <= '9' && s[len] >= '0')
			res += ex * (s[len] - '0');
		else
			return (-1);
		ex *= 16;
		len--;
	}
	return (res);
}
