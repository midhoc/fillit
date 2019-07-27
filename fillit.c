/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 01:53:42 by hmidoun           #+#    #+#             */
/*   Updated: 2019/07/27 03:26:38 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	 main(int argc, char **argv)
{
	int		fd;
	char	str[26][4][4];
	int		nbr_ttrs;

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



	printf("%d\n%d\n",check(fd, str, &nbr_ttrs),nbr_ttrs);
	int i = 0;
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
	}
	return (0);
}
