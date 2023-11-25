/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:55:52 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/24 15:02:49 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_inode
{
	int				number;
	unsigned int	index;
	struct s_inode	*next;
}	t_inode;

typedef struct s_stack
{
	t_inode		**head;
	t_inode		**tail;
	int			min;
	int			max;
	size_t		size;
}	t_stack;

//input processing
int		is_int(char *str);
int		is_in_range(long long nbr);
int		is_dup(int number, t_inode **head);
void	set_metadata(t_stack *stack);
void	update_meta(t_stack *stack);
void	process_input(int argc, char *argv[], t_stack *stack);

//list manipulation
unsigned int	lstsize(t_inode **head);
t_inode	**get_tail(t_inode **head);
t_inode	*create_node(int number);
void	append_node(t_inode **head, t_inode *new_node);
void	prepend_node(t_inode **head, t_inode *new_node);
void	destroy_list(t_inode **head);
void	print_list(t_inode **head);

//stack motions
void	swap(t_inode **head);
void	rot(t_inode **head);
void	rrot(t_inode **head);
void	push(t_inode **from, t_inode **to);

//sorting
int		is_ordered(t_inode **head);
unsigned int	get_index(t_inode **head, int nbr);
void	sort(t_stack *stack_a, t_stack *stack_b);
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
#endif //PUSH_SWAP_H
