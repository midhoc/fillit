/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midounhocine <midounhocine@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:18:40 by midounhocin       #+#    #+#             */
/*   Updated: 2019/05/10 12:59:18 by midounhocin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     main(int argc, char **argv)
{
    int     fd;

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
    printf("%d\n",check(fd));
    //*/
   /*
   char *line;
   fd = open("tst",O_RDONLY);
   for(int i = 0; i < 7;i++)
   {
    ft_putnbr(get_next_line(fd,&line));
    printf("\n%d\n%s\n",i,line);
   }
   */
    return (0);
}