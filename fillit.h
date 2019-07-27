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

int	 check(int fd, char ttrs[26][4][4], int *nbr_ttrs);
int	 get_ttrs(int fd, char str[26][4][4], int l);
int	 nbr_next_hash(const char str[4][4], int x, int y);
int	 check_ttrs(char str[4][4], int nbr_ttrs);

#endif
