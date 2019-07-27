/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ttrs_list1.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: midounhocine <midounhocine@student.42.f	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/05/09 12:07:26 by midounhocin	   #+#	#+#			 */
/*   Updated: 2019/05/09 15:31:48 by midounhocin	  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	 ttrs_0(char str[4][4], int str_y, int str_x)
{
	int i;
	int ttrs_x[3];
	int ttrs_y[3];

	ttrs_x[0] = 1;
	ttrs_x[1] = 2;
	ttrs_x[2] = 3;
	ttrs_y[0] = 0;
	ttrs_y[1] = 0;
	ttrs_y[2] = 0;
	i = 0;
	while (i < 3)
	{
		if(str[ttrs_y[i] + str_y ][ttrs_x[i] + str_x] != '#')
			return (0);
		i++;
	}
	return (1);
}

int	 ttrs_1(char str[4][4], int str_y, int str_x)
{
	int i;
	int ttrs_x[3];
	int ttrs_y[3];

	ttrs_y[0] = 1;
	ttrs_y[1] = 2;
	ttrs_y[2] = 3;
	ttrs_x[0] = 0;
	ttrs_x[1] = 0;
	ttrs_x[2] = 0;
	i = 0;
	while (i < 3)
	{
		if(str[ttrs_y[i] + str_y][ttrs_x[i] + str_x] != '#')
			return (0);
		i++;
	}
	return (1);
}

int	 ttrs_2(char str[4][4], int str_y, int str_x)
{
	int i;
	int ttrs_x[3];
	int ttrs_y[3];

	ttrs_x[0] = 1;
	ttrs_x[1] = 1;
	ttrs_x[2] = 0;
	ttrs_y[0] = 0;
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

int	 ttrs_3(char str[4][4], int str_y, int str_x)
{
	int i;
	int ttrs_x[3];
	int ttrs_y[3];

	ttrs_x[0] = 1;
	ttrs_x[1] = 0;
	ttrs_x[2] = -1;
	ttrs_y[0] = 0;
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

int	 ttrs_4(char str[4][4], int str_y, int str_x)
{
	int i;
	int ttrs_x[3];
	int ttrs_y[3];

	ttrs_x[0] = 0;
	ttrs_x[1] = 1;
	ttrs_x[2] = 1;
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
