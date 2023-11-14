/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:55:52 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/14 19:01:34 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_inode
{
	int				number;
	struct s_inode	*next;
	struct s_inode	*prev;
}	t_inode;

//input validation
int		is_int(char *str);
int		is_in_range(long long nbr);
int		is_dup(int number, t_inode **head);

//list manipulation
t_inode	*create_node(int number);
void	append_node(t_inode **head, t_inode *new_node);
void	destroy_list(t_inode **head);
#endif //PUSH_SWAP_H
