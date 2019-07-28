/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 15:41:58 by hmidoun           #+#    #+#             */
/*   Updated: 2019/07/28 17:00:36 by hmidoun          ###   ########.fr       */
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
	}
	return(str);
}

void	free_board(char ***str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		ft_strdel(str[i]);
		i++;
	}
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

	i = 0;
	board = creat_board(size);
	if(!board)
		return(NULL);
	while(*board)
	{
		while(i < size)
		{
			*board[i] = '.';
			i++;
		}
	}
	return(board);
}
