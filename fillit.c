/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 01:53:42 by hmidoun           #+#    #+#             */
/*   Updated: 2019/07/29 20:10:04 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	 main(int argc, char **argv)
{
	int			fd;
	ttrs_list	*head;
	int			nbr_ttrs;
	char		**board;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit file...");
		//return (0);
	}
	if ((fd = open("tst",O_RDONLY)) < 0)
	{
		ft_putendl("error");
		return (0);
	}



	printf("%d\n%d\n",check(fd, &head, &nbr_ttrs),nbr_ttrs);

	while(head)
	{
		for(int i = 0; i < 4; i++)
		{
			printf("%s\n",head->ttrs[i]);
		}
		printf("\n");
		head = head->next;

	}
	board = init_board(2);




ft_put_words_tables(board, 2);
free_board(board, 2);
board = init_board(5);
ft_put_words_tables(board, 5);
free_board(board, 5);
	return (0);
}
