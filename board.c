/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 15:41:58 by hmidoun           #+#    #+#             */
/*   Updated: 2019/07/29 20:06:42 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**creat_board(int size)
{
	char	**str;
	int		i;

	i = 0;
	str = (char **)malloc(sizeof(char *) * size);
	if (!str)
		return(NULL);
	while(i < size)
	{
		str[i] = ft_strnew(size);
		if(!str[i])
			return(NULL);
		i++;
	}

	return(str);
}

void	free_board(char **str, int tab_size)
{
	int	i;

	i = 0;
	while(i < tab_size)
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
}

int		board_size(int nbr_ttrs)
{
	if(nbr_ttrs <= 4)
		return(4);
	return(ft_sqrt_max(nbr_ttrs * 4));
}

char	**init_board(int size)
{
	char	**board;
	int		i;
	int		j;

	j = 0;
	board = creat_board(size);
	if(!board)
		return(NULL);
	while(j < size)
	{
		i = 0;
		while(i < size)
		{
			board[j][i] = '.';
			i++;
		}
		j++;
	}
	return(board);
}
/*
void	create_board(int size, char **board)
{
	int			row;
	int			col;

	row = -1;
	col = -1;
	while (++row < size)
	{
		if(!(board[row] = (char*)malloc(sizeof(char) * size)))
			return(0);
		col = -1;
		while (++col < size)
		{
			if (argv[row + 1][col] == '.')
				board[row][col] = 0;
			else
				board[row][col] = argv[row + 1][col] - '0';
		}
	}
}*/
