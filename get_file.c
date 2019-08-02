/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 01:26:55 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/01 20:47:28 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_ttrs(int fd, t_ttrs_list **new, int nbr_ttrs)
{
	int		i;
	char	*line;

	*new = (t_ttrs_list *)malloc(sizeof(t_ttrs_list));
	if (!(*new))
		return (0);
	(*new)->next = NULL;
	i = 0;
	while (i < 4)
	{
		if (get_next_line(fd, &line) <= 0)
		{
			free(*new);
			return (0);
		}
		if (!check_line_length(i, &line, new))
			return (0);
		i++;
		free(line);
	}
	if (check_ttrs((*new)->ttrs, nbr_ttrs) && get_origin(new))
		return (1);
	return (0);
}

int		check(int fd, t_ttrs_list **head, int *nbr_ttrs)
{
	char			*line;
	t_ttrs_list		*tmp;
	int				ret;

	tmp = NULL;
	*nbr_ttrs = 0;
	while (get_ttrs(fd, &tmp, *nbr_ttrs))
	{
		ft_ls_push_back_ttrs(head, tmp);
		(*nbr_ttrs)++;
		ret = get_next_line(fd, &line);
		if (ret == 0)
			return (1);
		if (ret == -1)
			return (0);
		if (ft_strlen(line) != 0)
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (0);
}

int		check_line_length(int i, char **line, t_ttrs_list **new)
{
	if (ft_strlen(*line) == 4)
	{
		ft_strcpy((*new)->ttrs[i], *line);
		(*new)->ttrs[i][4] = '\0';
	}
	else
	{
		free(*line);
		free(*new);
		return (0);
	}
	return (1);
}

int		check_ttrs(char str[4][5], int nbr_ttrs)
{
	int i;
	int j;
	int hash;
	int next_hash;

	next_hash = 0;
	hash = 0;
	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			if ((str[j][i] != '.' && str[j][i] != '#') || hash > 4)
				return (0);
			if (str[j][i] == '#' && ++hash)
			{
				str[j][i] = 'A' + nbr_ttrs;
				next_hash += nbr_next_hash(str, j, i);
			}
		}
	}
	if (hash != 4 || (next_hash != 8 && next_hash != 6))
		return (0);
	return (1);
}

int		nbr_next_hash(const char str[4][5], int x, int y)
{
	int nbr;

	nbr = 0;
	if (x < 3 && str[x + 1][y] != '.')
		nbr++;
	if (y < 3 && str[x][y + 1] != '.')
		nbr++;
	if (x > 0 && str[x - 1][y] != '.')
		nbr++;
	if (y > 0 && str[x][y - 1] != '.')
		nbr++;
	return (nbr);
}
