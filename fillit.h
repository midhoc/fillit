/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:47:29 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/01 01:12:00 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"

typedef struct s_ttrs_list	t_ttrs_list;
struct	s_ttrs_list
{
	char			ttrs[4][5];
	int				x_0;
	int				y_0;
	int				hight;
	int				weidth;
	t_ttrs_list		*next;
};

int		check(int fd, t_ttrs_list **head, int *nbr_ttrs);
int		get_ttrs(int fd, t_ttrs_list **head, int l);
int		nbr_next_hash(const char str[4][5], int x, int y);
int		check_ttrs(char str[4][5], int nbr_ttrs);
int		board_size(int nbr_ttrs);
void	free_board(char **str, int tab_size);
char	**creat_board(int size);
char	**init_board(int size);
int		get_origin(t_ttrs_list **head);
void	free_list(t_ttrs_list **head);
void	w_and_h(int i, int j, t_ttrs_list **head, int flag);
int		check_ttrs_board(char **board, int c[2], t_ttrs_list **h, int s);
void	put_ttrs_board(char **board, int cord[2], t_ttrs_list **head);
void	del_ttrs_board(char **board, int cord[2], t_ttrs_list **head);
int		back_track(char **board, t_ttrs_list **head, int size);
void	ft_ls_push_back_ttrs(t_ttrs_list **head, t_ttrs_list *new);
void	ft_put_words_tables(char **tab, int tab_size);
void	solve(int nbr_ttrs, t_ttrs_list **head);
int		check_line_length(int i, char **line, t_ttrs_list **new);
void	put_error(void);

#endif
