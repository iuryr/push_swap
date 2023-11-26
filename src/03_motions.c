/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_motions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:09:29 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/21 11:11:30 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *s, int flag)
{
	t_inode	*first;
	t_inode	*second;
	t_inode	*last;

	if (*s->head == NULL || (*s->head)->next == *s->head)
		return ;
	first = *s->head;
	second = first->next;
	last = *s->head;
	while (last->next != *s->head)
		last = last->next;
	if (last->next->next == last)
	{
		first->next = second;
		second->next = first;
		*s->head = second;
		return ;
	}
	first->next = second->next;
	second->next = first;
	*s->head = second;
	last->next = *s->head;
	if (flag == 0)
		ft_printf("sa\n");
	update_meta(s);
}

void	rot(t_stack *s, int flag)
{
	*s->head = (*s->head)->next;
	if (flag == 0)
		ft_printf("ra\n");
	if (flag == 1)
		ft_printf("rb\n");
	update_meta(s);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rot(stack_a, 2);
	rot(stack_b, 2);
	ft_printf("rr\n");
}

void	rrot(t_stack *s, int flag)
{
	t_inode	*og_head;

	og_head = *s->head;
	if ((*s->head)->next == *s->head)
		return ;
	while (og_head->next != *s->head)
		og_head = og_head->next;
	*s->head = og_head;
	if (flag == 0)
		ft_printf("rra\n");
	if (flag == 1)
		ft_printf("rrb\n");
	update_meta(s);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rrot(stack_a, 2);
	rrot(stack_b, 2);
	ft_printf("rrr\n");
}

void	push(t_stack *from, t_stack *to)
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
		return ;
	}
	while (last->next != *from->head)
		last = last->next;
	last->next = (*from->head)->next;
	*from->head = (*from->head)->next;
	prepend_node(to->head, old_first);
	update_meta(from);
	update_meta(to);
}

int	apply_rarb(t_stack *stack_a, t_stack *stack_b, int nbr, char s)
{
	if (s == 'a')
	{
		while((*stack_a->head)->number != nbr && get_insert_index(stack_b, nbr) > 0)
			rr(stack_a, stack_b);
		while((*stack_a->head)->number != nbr)
			rot(stack_a->head, 0);
		while(get_insert_index(stack_b, nbr) > 0)
			rot(stack_b->head, 1);
		push(stack_a->head, stack_b->head);
		ft_printf("pb\n");
		update_meta(stack_a);
		update_meta(stack_b);
	}
	else
	{
		while((*stack_b->head)->number != nbr && get_insert_index(stack_a, nbr) > 0)
			rr(stack_a, stack_b);
		while((*stack_b->head)->number != nbr)
			rot(stack_b->head, 1);
		while (get_insert_index(stack_a, nbr))
			rot(stack_a->head, 0);
		push(stack_b->head, stack_a->head);
		ft_printf("pa\n");
	}
	return (-1);
}

int	apply_rrarrb(t_stack *stack_a, t_stack *stack_b, int nbr, char s)
{
	if (s == 'a')
	{
		while((*stack_a->head)->number != nbr && get_insert_index(stack_b, nbr))
			rrr(stack_a, stack_b);
		while((*stack_a->head)->number != nbr)
			rrot(stack_a->head, 0);
		while(get_insert_index(stack_b, nbr) > 0)
			rrot(stack_b->head, 1);
		push(stack_a->head, stack_b->head);
		ft_printf("pb\n");
	}
	else
	{
		while((*stack_b->head)->number != nbr && get_insert_index(stack_a, nbr) > 0)
			rrr(stack_a, stack_b);
		while((*stack_b->head)->number != nbr)
			rrot(stack_b->head, 1);
		while (get_insert_index(stack_a, nbr))
			rrot(stack_a->head, 0);
		push(stack_b->head, stack_a->head);
		ft_printf("pa\n");
	}
	return (-1);
}

int	apply_rarrb(t_stack *stack_a, t_stack *stack_b, int nbr, char s)
{
	if (s == 'a')
	{
		while ((*stack_a->head)->number != nbr)
			rot(stack_a->head, 0);
		while(get_insert_index(stack_b, nbr) > 0)
			rrot(stack_b->head, 1);
		push(stack_a->head, stack_b->head);
		ft_printf("pb\n");
	}
	else
	{
		while ((*stack_b->head)->number != nbr)
			rot(stack_b->head, 1);
		while (get_insert_index(stack_a, nbr) > 0)
			rrot(stack_a->head, 0);
		push(stack_b->head, stack_a->head);
		ft_printf("pa\n");
	}
	return (-1);
}

int	apply_rrarb(t_stack *stack_a, t_stack *stack_b, int nbr, char s)
{
	if (s == 'a')
	{
		while ((*stack_a->head)->number != nbr)
			rrot(stack_a->head, 0);
		while (get_insert_index(stack_b, nbr) > 0)
			rot(stack_b->head, 1);
		push(stack_a->head, stack_b->head);
		ft_printf("pb\n");
	}
	else
	{
		while (get_insert_index(stack_a, nbr) > 0)
			rrot(stack_a->head, 0);
		while ((*stack_b->head)->number != nbr)
			rot(stack_b->head, 1);
		push(stack_b->head, stack_a->head);
		ft_printf("pa\n");
	}
	return (-1);
}

int	min_cost_ab(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	t_inode *tmp;

	i = sim_revrot_number(stack_a, stack_b, (*stack_a->head)->number);
	tmp = *stack_a->head;
	while (tmp->next != *stack_a->head)
	{
		if (i > sim_rot_number(stack_a, stack_b, tmp->number))
			i = sim_rot_number(stack_a, stack_b, tmp->number);
		if (i > sim_revrot_number(stack_a, stack_b, tmp->number))
			i = sim_revrot_number(stack_a, stack_b, tmp->number);
		if (i > rarrb_number(stack_a, stack_b, tmp->number))
			i = rarrb_number(stack_a, stack_b, tmp->number);
		if (i > rrarb_number(stack_a, stack_b, tmp->number))
			i = rrarb_number(stack_a, stack_b, tmp->number);
		tmp = tmp->next;
	}
	if (i > sim_rot_number(stack_a, stack_b, tmp->number))
		i = sim_rot_number(stack_a, stack_b, tmp->number);
	if (i > sim_revrot_number(stack_a, stack_b, tmp->number))
		i = sim_revrot_number(stack_a, stack_b, tmp->number);
	if (i > rarrb_number(stack_a, stack_b, tmp->number))
		i = rarrb_number(stack_a, stack_b, tmp->number);
	if (i > rrarb_number(stack_a, stack_b, tmp->number))
		i = rrarb_number(stack_a, stack_b, tmp->number);
	return (i);
}

void	proper_push_b(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	t_inode *tmp;

	while (stack_a->size > 3 && !is_ordered(stack_a->head))
	{
		tmp = *stack_a->head;
		i = min_cost_ab(stack_a, stack_b);
		while (i >= 0)
		{
			if (i == sim_rot_number(stack_a, stack_b, tmp->number))
				i = apply_rarb(stack_a, stack_b, tmp->number, 'a');
			else if (i == sim_revrot_number(stack_a, stack_b, tmp->number))
				i = apply_rrarrb(stack_a, stack_b, tmp->number, 'a');
			else if (i == rarrb_number(stack_a, stack_b, tmp->number))
				i = apply_rarrb(stack_a, stack_b, tmp->number, 'a');
			else if (i == rrarb_number(stack_a, stack_b, tmp->number))
				i = apply_rrarb(stack_a, stack_b, tmp->number, 'a');
			else
			 tmp = tmp->next;
		}
		update_meta(stack_a);
		update_meta(stack_b);
	}
}
