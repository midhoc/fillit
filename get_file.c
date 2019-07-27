/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 01:26:55 by hmidoun           #+#    #+#             */
/*   Updated: 2019/07/27 02:38:03 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	 get_ttrs(int fd, char str[26][4][4], int nbr_ttrs)
{
	int	 i;
	char	*line;

	i = 0;
	while (i < 4)
	{
		if(!get_next_line(fd, &line))
			return (0);
		if(ft_strlen(line) == 4)
				ft_strcpy(str[nbr_ttrs][i],line);
		else
			return (0);
		i++;
	}
	if(check_ttrs(str[nbr_ttrs],nbr_ttrs))
		return (1);
	return (0);
}

int check(int fd, char ttrs[26][4][4], int *nbr_ttrs)
{
	char	*line;

	*nbr_ttrs = 0;
	while (get_ttrs(fd,ttrs, *nbr_ttrs))
	{
		(*nbr_ttrs)++;
		if (get_next_line(fd, &line) <= 0)
			return (1);
		if (ft_strlen(line) != 0)
			return (0);
	}
	return (0);
}
