/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 01:53:42 by hmidoun           #+#    #+#             */
/*   Updated: 2019/07/27 21:49:08 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	 main(int argc, char **argv)
{
	int			fd;
	ttrs_list		*head;
	int			nbr_ttrs;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit file...");
		return (0);
	}
	if ((fd = open(argv[1],O_RDONLY)) < 0)
	{
		ft_putendl("error");
		return (0);
	}



	printf("%d\n%d\n",check(fd, &head, &nbr_ttrs),nbr_ttrs);

	while(head)
	{
		printf("%s\n",head->ttrs);
		head = head->next;

	}


	/*int i = 0;
	int j,k;
	while(i<nbr_ttrs)
	{
		j = 0;

		while(j < 4)
		{
			k=0;

			while(k < 4)
			{
				ft_putchar(str[i][j][k]);
				k++;
			}
			ft_putchar('\n');
			j++;
		}
		ft_putchar('\n');
		i++;
	}*/
	return (0);
}
