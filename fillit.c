/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 01:53:42 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/01 20:48:19 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	t_ttrs_list	*head;
	int			nbr_ttrs;

	head = NULL;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit file");
		exit(0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		put_error();
	if (!check(fd, &head, &nbr_ttrs) || close(fd) != 0 || nbr_ttrs > 26)
	{
		free_list(&head);
		put_error();
	}
	solve(nbr_ttrs, &head);
	return (0);
}

void	put_error(void)
{
	ft_putendl("error");
	exit(0);
}
