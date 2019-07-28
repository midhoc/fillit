/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   fillit.h										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: midounhocine <midounhocine@student.42.f	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/04/30 20:20:54 by midounhocin	   #+#	#+#			 */
/*   Updated: 2019/07/26 22:32:49 by midounhocin	  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"

typedef struct ttrs_list	ttrs_list;
struct	ttrs_list
{
	char		ttrs[4][5];
	int			type;
	ttrs_list		*next;
};

int	 	check(int fd, ttrs_list **head, int *nbr_ttrs);
int	 	get_ttrs(int fd, ttrs_list **head, int l);
int	 	nbr_next_hash(const char str[4][5], int x, int y);
int	 	check_ttrs(char str[4][5], int nbr_ttrs);
int		board_size(int nbr_ttrs);
void	free_board(char ***str);
char	**creat_board(int size);
char	**init_board(int size);


#endif
