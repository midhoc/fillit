/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:19:43 by hmidoun           #+#    #+#             */
/*   Updated: 2019/07/31 22:56:34 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_origin(t_ttrs_list **head)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	(*head)->x_0 = 4;
	(*head)->y_0 = 4;
	(*head)->weidth = 0;
	(*head)->hight = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((*head)->ttrs[i][j] != '.')
			{
				w_and_h(i, j, head, 0);
			}
			j++;
		}
		i++;
	}
	w_and_h(i, j, head, 1);
	return (1);
}

void	w_and_h(int i, int j, t_ttrs_list **head, int flag)
{
	if (flag)
	{
		(*head)->weidth -= (*head)->x_0;
		(*head)->hight -= (*head)->y_0;
		return ;
	}
	if ((*head)->x_0 > j)
		(*head)->x_0 = j;
	if ((*head)->y_0 > i)
		(*head)->y_0 = i;
	if ((*head)->weidth < j)
		(*head)->weidth = j;
	if ((*head)->hight < i)
		(*head)->hight = i;
}

void	ft_put_words_tables(char **tab, int tab_size)
{
	int i;

	i = 0;
	while (i < tab_size)
	{
		ft_putstr(tab[i]);
		i++;
		ft_putchar('\n');
	}
}

void	ft_ls_push_back_ttrs(t_ttrs_list **head, t_ttrs_list *new)
{
	t_ttrs_list		*temp;

	temp = *head;
	if (temp == NULL)
		*head = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void	free_list(t_ttrs_list **head)
{
	if (*head)
	{
		free_list(&(*head)->next);
		free(*head);
	}
}
