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
	t_inode		*tail;
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
t_inode	*get_tail(t_inode **head);
t_inode	*create_node(int number);
void	append_node(t_inode **head, t_inode *new_node);
void	prepend_node(t_inode **head, t_inode *new_node);
void	destroy_list(t_inode **head);
void	print_list(t_inode **head);

//stack motions
void	swap(t_stack *s, int flag);
void	rot(t_stack *s, int flag);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrot(t_stack *s, int flag);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *from, t_stack *to, int c);
int	apply_rarb(t_stack *stack_a, t_stack *stack_b, int nbr, char s);
int	apply_rrarrb(t_stack *stack_a, t_stack *stack_b, int nbr, char s);
int	apply_rarrb(t_stack *stack_a, t_stack *stack_b, int nbr, char s);
int	apply_rrarb(t_stack *stack_a, t_stack *stack_b, int nbr, char s);

//sorting
int	is_ordered(t_stack *s);
unsigned int	get_index(t_inode **head, int nbr);
int	get_insert_index(t_stack *stack, int nbr);
void	sort(t_stack *stack_a, t_stack *stack_b);
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
int	sim_rot_number(t_stack *stack_a, t_stack *stack_b, int nbr);
int	sim_revrot_number(t_stack *stack_a, t_stack *stack_b, int nbr);
int	rarrb_number(t_stack *stack_a, t_stack *stack_b, int nbr);
int	rrarb_number(t_stack *stack_a, t_stack *stack_b, int nbr);
int	min_cost_ab(t_stack *stack_a, t_stack *stack_b);
void	proper_push_b(t_stack *stack_a, t_stack *stack_b);
#endif //PUSH_SWAP_H
