/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 01:26:55 by hmidoun           #+#    #+#             */
/*   Updated: 2019/07/27 22:08:41 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	 get_ttrs(int fd, ttrs_list **new, int nbr_ttrs)
{
	int	 i;
	char	*line;

	*new  = (ttrs_list *)malloc(sizeof(ttrs_list));
	i = 0;
	while (i < 4)
	{
		if(!get_next_line(fd, &line))
			return (0);
		if(ft_strlen(line) == 4)
				ft_strcpy((*new)->ttrs[i],line);
		else
			return (0);
		i++;
	}
	if(check_ttrs((*new)->ttrs,nbr_ttrs))
		return (1);
	return (0);
}

int check(int fd, ttrs_list **head, int *nbr_ttrs)
{
	char			*line;
	ttrs_list		*tmp;

	tmp = *head;
	*nbr_ttrs = 0;
	while (get_ttrs(fd, &tmp, *nbr_ttrs))
	{
		tmp->next = *head;
		*head = tmp;
		(*nbr_ttrs)++;
		if (get_next_line(fd, &line) <= 0)
			return (1);
		if (ft_strlen(line) != 0)
			return (0);

	}
	return (0);
}
