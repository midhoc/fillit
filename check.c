/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midounhocine <midounhocine@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:38:47 by midounhocin       #+#    #+#             */
/*   Updated: 2019/05/10 13:24:20 by midounhocin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <string.h>

int     check_ttrs(char str[4][4], int start[2])
{
    int i;
    int j;
    int hash;

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
                if (hash == 0)
                {
                    start[0] = j;
                    start[1] = i;
                }
                hash++;
            }
            i++;
        }
        j++;
    }
    if (hash != 4)
        return (0);
    return(1);
}

int     type_ttrs(char str[4][4], int start_y, int start_x)
{
   /* int ttrs[19][4];
    ttrs[][] = ,{0,10,11,21},{0,1,11,12},{0,10,-11,-21},
    {0,1,2,12},{0,10,20,-21},{0,10,11,12},{0,1,10,20},{0,1,2,11},
    {0,10,20,-11},{0,10,11,-11},{0,10,11,20},{0,1,2,10},{0,1,11,12},
    {0,10,-11,-12},{0,10,20,21}};
    */
    int     (*f[19])(char [4][4], int, int);
    int     i;

    i = -1;
    f[0] = ttrs_0;
    f[1] = ttrs_1;
    f[2] = ttrs_2;
    f[3] = ttrs_3;
    f[4] = ttrs_4;
    f[5] = ttrs_5;
    f[6] = ttrs_6;
    f[7] = ttrs_7;
    f[8] = ttrs_8;
    f[9] = ttrs_9;
    f[10] = ttrs_10;
    f[11] = ttrs_11;
    f[12] = ttrs_12;
    f[13] = ttrs_13;
    f[14] = ttrs_14;
    f[15] = ttrs_15;
    f[16] = ttrs_16;
    f[17] = ttrs_17;
    f[18] = ttrs_18;
    while (++i <= 18 &&!f[i](str, start_y, start_x));
    return (i);
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
            return (19);
        if(ft_strlen(line) == 4)
                strcpy(str[i],line);
        else
            return (19);
        i++;
    }
    if(check_ttrs(str, start))
            return (type_ttrs(str, start[0], start[1]));
    return (19);
}
int check(int fd)
{
    char    *line;
    int     i;
    int     next;

    i = 0;
    while (get_ttrs(fd) < 19)
    {
        if (!get_next_line(fd, &line))
            return (1);
        if (ft_strlen(line) != 0)
            return (0);
        i++;
        next = 1;
    }
    printf("fail ttrs : %d",i);
    return (0);
}