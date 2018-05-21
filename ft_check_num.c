/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 11:30:39 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/19 16:39:55 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_check_num(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-' && str[i + 1] == '-')
		error(3);
	if (str[i] == '+' && str[i + 1] == '+')
		error(3);
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-' ||
					str[i] == ',' || (str[i] <= 'F' && str[i] >= 'A') ||
					str[i] == 'x'))
			error(3);
		i++;
	}
	return (1);
}
