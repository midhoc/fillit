/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:19:43 by hmidoun           #+#    #+#             */
/*   Updated: 2019/07/30 04:08:21 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_origin(ttrs_list **head)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	(*head)->x_0 = 4;
	(*head)->y_0 = 4;
	(*head)->weidth = 0;
	(*head)->hight = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			if((*head)->ttrs[i][j] != '.')
				{
					w_h_O(i, j, head, 0);
				}
			j++;
		}
	i++;
	}
	w_h_O(i, j, head, 1);
	return (1);
}

void	w_h_O(int i, int j, ttrs_list **head, int flag)
{
	if(flag)
	{
		(*head)->weidth -= (*head)->x_0;
		(*head)->hight -= (*head)->y_0;
		return;
	}
	if((*head)->x_0 > j)
		(*head)->x_0 = j;
	if((*head)->y_0 > i)
		(*head)->y_0 = i;
	if((*head)->weidth < j)
		(*head)->weidth = j;
	if((*head)->hight < i)
		(*head)->hight = i;
}
