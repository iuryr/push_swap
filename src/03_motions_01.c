/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_motions_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:54:22 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/27 11:25:00 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack *from, t_stack *to, int c)
{
	t_inode	*last;
	t_inode	*old_first;

	if (*from->head == NULL)
		return ;
	old_first = *from->head;
	last = *from->head;
	if (old_first->next == old_first)
	{
		prepend_node(to->head, old_first);
		*from->head = NULL;
		update_meta(to);
		print_push(c);
		return ;
	}
	while (last->next != *from->head)
		last = last->next;
	last->next = (*from->head)->next;
	*from->head = (*from->head)->next;
	prepend_node(to->head, old_first);
	update_meta(from);
	update_meta(to);
	print_push(c);
}

int	apply_rarb(t_stack *stack_a, t_stack *stack_b, int nbr, char s)
{
	if (s == 'a')
	{
		while ((*stack_a->head)->number != nbr
			&& get_insert_index(stack_b, nbr) > 0)
			rr(stack_a, stack_b);
		while ((*stack_a->head)->number != nbr)
			rot(stack_a, 0);
		while (get_insert_index(stack_b, nbr) > 0)
			rot(stack_b, 1);
		push(stack_a, stack_b, 0);
	}
	else
	{
		while ((*stack_b->head)->number != nbr
			&& get_insert_index_a(stack_a, nbr) > 0)
			rr(stack_a, stack_b);
		while ((*stack_b->head)->number != nbr)
			rot(stack_b, 1);
		while (get_insert_index_a(stack_a, nbr))
			rot(stack_a, 0);
		push(stack_b, stack_a, 1);
	}
	return (-1);
}

int	apply_rrarrb(t_stack *stack_a, t_stack *stack_b, int nbr, char s)
{
	if (s == 'a')
	{
		while ((*stack_a->head)->number != nbr
			&& get_insert_index(stack_b, nbr))
			rrr(stack_a, stack_b);
		while ((*stack_a->head)->number != nbr)
			rrot(stack_a, 0);
		while (get_insert_index(stack_b, nbr) > 0)
			rrot(stack_b, 1);
		push(stack_a, stack_b, 0);
	}
	else
	{
		while ((*stack_b->head)->number != nbr
			&& get_insert_index_a(stack_a, nbr) > 0)
			rrr(stack_a, stack_b);
		while ((*stack_b->head)->number != nbr)
			rrot(stack_b, 1);
		while (get_insert_index_a(stack_a, nbr))
			rrot(stack_a, 0);
		push(stack_b, stack_a, 1);
	}
	return (-1);
}

int	apply_rarrb(t_stack *stack_a, t_stack *stack_b, int nbr, char s)
{
	if (s == 'a')
	{
		while ((*stack_a->head)->number != nbr)
			rot(stack_a, 0);
		while (get_insert_index(stack_b, nbr) > 0)
			rrot(stack_b, 1);
		push(stack_a, stack_b, 0);
	}
	else
	{
		while ((*stack_b->head)->number != nbr)
			rot(stack_b, 1);
		while (get_insert_index_a(stack_a, nbr) > 0)
			rrot(stack_a, 0);
		push(stack_b, stack_a, 1);
	}
	return (-1);
}

int	apply_rrarb(t_stack *stack_a, t_stack *stack_b, int nbr, char s)
{
	if (s == 'a')
	{
		while ((*stack_a->head)->number != nbr)
			rrot(stack_a, 0);
		while (get_insert_index(stack_b, nbr) > 0)
			rot(stack_b, 1);
		push(stack_a, stack_b, 0);
	}
	else
	{
		while (get_insert_index_a(stack_a, nbr) > 0)
			rrot(stack_a, 0);
		while ((*stack_b->head)->number != nbr)
			rot(stack_b, 1);
		push(stack_b, stack_a, 1);
	}
	return (-1);
}
