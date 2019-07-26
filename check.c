/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midounhocine <midounhocine@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:38:47 by midounhocin       #+#    #+#             */
/*   Updated: 2019/07/26 23:04:50 by midounhocin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     check_ttrs(const char str[4][4])
{
    int i;
    int j;
    int hash;
    int next_hash;

    next_hash = 0;
    hash = 0;
    j = 0;
    while (j < 4)
    {
        i = 0;
        while (i < 4)
        {
            if ((str[j][i] != '.' && str[j][i] != '#') || hash > 4)
                return (0);
            if (str[j][i] == '#')
            {
                hash++;
                next_hash += nbr_next_hash(str, j, i);
            }
            i++;
        }
        j++;
    }
    if (hash != 4 || (next_hash != 8 && next_hash != 6))
        return (0);
    return(1);
}

int     nbr_next_hash(const char str[4][4], int x, int y)
{
    int nbr;

    nbr = 0;
    if(x < 3 && str[x + 1][y] == '#')
        nbr++;
    if(y < 3 && str[x][y + 1] == '#')
        nbr++;
    if(x > 0 && str[x - 1][y] == '#')
        nbr++;
    if(y > 0 && str[x][y - 1] == '#')
        nbr++;
    return(nbr);
}

int     get_ttrs(int fd)
{
    int     i;
    int     start[2];
    char    *line;
    char    str[4][4];
    
    i = 0;
    while (i < 4)
    {
        if(!get_next_line(fd, &line))
            return (0);
        if(ft_strlen(line) == 4)
                strcpy(str[i],line);
        else
            return (0);
        i++;
    }
    if(check_ttrs(str))
            return (1);
    return (0);
}
int check(int fd)
{
    char    *line;
    int     i;
    int     next;

    i = 0;
    while (get_ttrs(fd))
    {
        if (get_next_line(fd, &line) <= 0)
            return (1);
        if (ft_strlen(line) != 0)
            return (0);
        i++;
        next = 1;
    }
    printf("fail ttrs : %d\n",i + 1);
    return (0);
}