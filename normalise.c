/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:19:43 by hmidoun           #+#    #+#             */
/*   Updated: 2019/07/29 21:42:06 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_origin(char	str[4][5], int *x, int *y)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	*x = 4;
	*y = 4;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			if(str[i][j] != '.')
				{
					if(*x > i)
						*x = i;
					if(*y > j)
						*y = j;
				}
			j++;
		}
	i++;
	}
}
