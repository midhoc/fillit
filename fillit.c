/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 01:53:42 by hmidoun           #+#    #+#             */
/*   Updated: 2019/07/31 01:50:23 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	 main(int argc, char **argv)
{
	int			fd;
	ttrs_list	*head;
	int			nbr_ttrs;
	char		**board;

	head = NULL;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit file...");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putendl("error");
		return (0);
	}


	//printf("%d\n%d\n",check(fd, &head, &nbr_ttrs),nbr_ttrs);
	//check(fd, &head, &nbr_ttrs);
/*
	while(head)
	{
		for(int i = 0; i < 4; i++)
		{
			printf("%s\n",head->ttrs[i]);
		}
		printf("\n");
		//liste needs to be free
		head = head->next;

	}*/
/*
while(head)
{
//get_origin(&head);

printf("%d\t%d\t%d\t%d\n",head->x_0,head->y_0,head->weidth,head->hight);
head = head->next;
}*/
/*
board = init_board(2);
ft_put_words_tables(board, 2);
free_board(board, 2);
board = init_board(5);
ft_put_words_tables(board, 5);
free_board(board, 5);
*/

if(!check(fd, &head, &nbr_ttrs))
{
	printf("error\n");
	free_list(&head);
	return(0);
}

int tst = board_size(nbr_ttrs);

board = init_board(tst);

while(!back_track(board, &head, tst))
{
	free_board(board, tst);
	tst++;
	board = init_board(tst);
}
	ft_put_words_tables(board, tst);
	free_board(board, tst);
	free_list(&head);
	printf("\nnbr_ttrs : %d \t size board : %d\n", nbr_ttrs, tst);
	//while(1);
	return (0);
}

void	free_list(ttrs_list **head)
{
	if(*head)
	{
		free_list(&(*head)->next);
		free(*head);
	}
}
