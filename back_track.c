/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 02:36:20 by hmidoun           #+#    #+#             */
/*   Updated: 2019/07/31 00:24:21 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_ttrs_board(char **board,int cord[2],ttrs_list **head,int size)
{
	int i;
	int j;

	j = 0;
	if(cord[0] + (*head)->weidth >= size|| cord[1] + (*head)->hight >= size)
		return(0);
	while(j <=  (*head)->hight)
	{
		i = 0;
		while(i <= (*head)->weidth)
		{
			if((*head)->ttrs[j + (*head)->y_0][i + (*head)->x_0] != '.' && board[j + cord[1]][i + cord[0]] != '.')
				return(0);
			i++;
		}
		j++;
	}
	put_ttrs_board(board, cord, head);
	return(1);
}

void	put_ttrs_board(char **board,int cord[2],ttrs_list **head)
{
	int i;
	int j;

	j = 0;
	while(j <=  (*head)->hight)
	{
		i = 0;
		while(i <= (*head)->weidth)
		{
			if((*head)->ttrs[j + (*head)->y_0][i + (*head)->x_0] != '.')
				board[j + cord[1]][i + cord[0]] = (*head)->ttrs[j + (*head)->y_0][i + (*head)->x_0];
			i++;
		}
		j++;
	}
}

void	del_ttrs_board(char **board,int cord[2],ttrs_list **head)
{
	int i;
	int j;

	j = 0;
	while(j <=  (*head)->hight)
	{
		i = 0;
		while(i <= (*head)->weidth)
		{
			if((*head)->ttrs[j + (*head)->y_0][i + (*head)->x_0] != '.')
				board[j + cord[1]][i + cord[0]] = '.';
			i++;
		}
		j++;
	}
}

int		back_track(char **board, ttrs_list **head, int size)
{
	int cord[2];

	if (!(*head))
		return (1);
	cord[1] = 0;
	while (cord[1] < size)
	{
		cord[0] = 0;
		while(cord[0] < size)
		{
			if (check_ttrs_board(board, cord, head, size))
			{
				if(back_track(board, &(*head)->next, size))
					return (1);
				else
					del_ttrs_board(board, cord, head);
			}
			cord[0]++;
		}
		cord[1]++;
	}
	return (0);
}

//void	solve_fillit()
