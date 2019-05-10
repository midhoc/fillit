/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttrs_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midounhocine <midounhocine@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:07:26 by midounhocin       #+#    #+#             */
/*   Updated: 2019/05/09 14:17:05 by midounhocin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 
int     ttrs_5(char str[4][4], int str_y, int str_x)
{
    int i;
    int ttrs_x[3];
    int ttrs_y[3];

    ttrs_x[0] = 1;
    ttrs_x[1] = 1;
    ttrs_x[2] = 2;
    ttrs_y[0] = 0;
    ttrs_y[1] = 1;
    ttrs_y[2] = 2;
    i = 0;
    while (i < 3)
    {
        if(str[ttrs_y[i] + str_y][ttrs_x[i] + str_x] != '#')
            return (0);
        i++;
    }
    return (1);
}

int     ttrs_6(char str[4][4], int str_y, int str_x)
{
    int i;
    int ttrs_x[3];
    int ttrs_y[3];

    ttrs_x[0] = 0;
    ttrs_x[1] = -1;
    ttrs_x[2] = -1;
    ttrs_y[0] = 1;
    ttrs_y[1] = 1;
    ttrs_y[2] = 2;
    i = 0;
    while (i < 3)
    {
        if(str[ttrs_y[i] + str_y][ttrs_x[i] + str_x] != '#')
            return (0);
        i++;
    }
    return (1);
}
 //  {0,1,2,12},
int     ttrs_7(char str[4][4], int str_y, int str_x)
{
    int i;
    int ttrs_x[3];
    int ttrs_y[3];

    ttrs_x[0] = 1;
    ttrs_x[1] = 2;
    ttrs_x[2] = 2;
    ttrs_y[0] = 0;
    ttrs_y[1] = 0;
    ttrs_y[2] = 1;
    i = 0;
    while (i < 3)
    {
        if(str[ttrs_y[i] + str_y][ttrs_x[i] + str_x] != '#')
            return (0);
        i++;
    }
    return (1);
}
//{0,10,20,-21},
int     ttrs_8(char str[4][4], int str_y, int str_x)
{
    int i;
    int ttrs_x[3];
    int ttrs_y[3];

    ttrs_x[0] = 0;
    ttrs_x[1] = 0;
    ttrs_x[2] = -1;
    ttrs_y[0] = 1;
    ttrs_y[1] = 2;
    ttrs_y[2] = 2;
    i = 0;
    while (i < 3)
    {
        if(str[ttrs_y[i] + str_y][ttrs_x[i] + str_x] != '#')
            return (0);
        i++;
    }
    return (1);
}
//{0,10,11,12},
int     ttrs_9(char str[4][4], int str_y, int str_x)
{
    int i;
    int ttrs_x[3];
    int ttrs_y[3];

    ttrs_x[0] = 0;
    ttrs_x[1] = 1;
    ttrs_x[2] = 2;
    ttrs_y[0] = 1;
    ttrs_y[1] = 1;
    ttrs_y[2] = 1;
    i = 0;
    while (i < 3)
    {
        if(str[ttrs_y[i] + str_y][ttrs_x[i] + str_x] != '#')
            return (0);
        i++;
    }
    return (1);
}