/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 01:53:53 by hmidoun           #+#    #+#             */
/*   Updated: 2019/07/27 02:58:04 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	 check_ttrs(char str[4][4], int nbr_ttrs)
{
	int i;
	int j;
	int hash;
	int next_hash;

	next_hash = 0;
	hash = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if ((str[j][i] != '.' && str[j][i] != '#') || hash > 4)
				return (0);
			if (str[j][i] == '#')
			{
				hash++;
				str[j][i] = 'A' + nbr_ttrs;
				next_hash += nbr_next_hash(str, j, i);
			}
			i++;
		}
		j++;
	}
	if (hash != 4 || (next_hash != 8 && next_hash != 6))
		return (0);
	return(1);
}

int	 nbr_next_hash(const char str[4][4], int x, int y)
{
	int nbr;

	nbr = 0;
	if(x < 3 && str[x + 1][y] != '.')
		nbr++;
	if(y < 3 && str[x][y + 1] != '.')
		nbr++;
	if(x > 0 && str[x - 1][y] != '.')
		nbr++;
	if(y > 0 && str[x][y - 1]!= '.')
		nbr++;
	return(nbr);
}
