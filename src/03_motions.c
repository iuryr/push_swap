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
		ft_printf("pa\n");
		return ;
	}
	while (last->next != *from->head)
		last = last->next;
	last->next = (*from->head)->next;
	*from->head = (*from->head)->next;
	prepend_node(to->head, old_first);
	update_meta(from);
	update_meta(to);
	if (c == 0)
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
}

int	apply_rarb(t_stack *stack_a, t_stack *stack_b, int nbr, char s)
{
	if (s == 'a')
	{
		while((*stack_a->head)->number != nbr && get_insert_index(stack_b, nbr) > 0)
			rr(stack_a, stack_b);
		while((*stack_a->head)->number != nbr)
			rot(stack_a, 0);
		while(get_insert_index(stack_b, nbr) > 0)
			rot(stack_b, 1);
		push(stack_a, stack_b, 0);
	}
	else
	{
		while((*stack_b->head)->number != nbr && get_insert_index_a(stack_a, nbr) > 0)
			rr(stack_a, stack_b);
		while((*stack_b->head)->number != nbr)
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
		while((*stack_a->head)->number != nbr && get_insert_index(stack_b, nbr))
			rrr(stack_a, stack_b);
		while((*stack_a->head)->number != nbr)
			rrot(stack_a, 0);
		while(get_insert_index(stack_b, nbr) > 0)
			rrot(stack_b, 1);
		push(stack_a, stack_b, 0);
	}
	else
	{
		while((*stack_b->head)->number != nbr && get_insert_index_a(stack_a, nbr) > 0)
			rrr(stack_a, stack_b);
		while((*stack_b->head)->number != nbr)
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
		while(get_insert_index(stack_b, nbr) > 0)
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

int	min_cost_ba(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	t_inode	*tmp;

	tmp = *stack_b->head;
	i = sim_revrot_number_a(stack_a, stack_b, (*stack_b->head)->number);
	while (tmp->next != *stack_b->head)
	{
		if (i > sim_rot_number_a(stack_a, stack_b, tmp->number))
			i = sim_rot_number_a(stack_a, stack_b, tmp->number);
		if (i > sim_revrot_number_a(stack_a, stack_b, tmp->number))
			i = sim_revrot_number_a(stack_a, stack_b, tmp->number);
		if (i > rarrb_number_a(stack_a, stack_b, tmp->number))
			i = rarrb_number_a(stack_a, stack_b, tmp->number);
		if (i > rrarb_number_a(stack_a, stack_b, tmp->number))
			i = rrarb_number_a(stack_a, stack_b, tmp->number);
		tmp = tmp->next;
	}
	if (i > sim_rot_number_a(stack_a, stack_b, tmp->number))
		i = sim_rot_number_a(stack_a, stack_b, tmp->number);
	if (i > sim_revrot_number_a(stack_a, stack_b, tmp->number))
		i = sim_revrot_number_a(stack_a, stack_b, tmp->number);
	if (i > rarrb_number_a(stack_a, stack_b, tmp->number))
		i = rarrb_number_a(stack_a, stack_b, tmp->number);
	if (i > rrarb_number_a(stack_a, stack_b, tmp->number))
		i = rrarb_number_a(stack_a, stack_b, tmp->number);
	return (i);
}

void	proper_push_b(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	t_inode *tmp;

	while (stack_a->size > 3 && !is_ordered(stack_a))
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
	}
}

void	proper_push_a(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	t_inode *tmp;

	while (*stack_b->head)
	{
		tmp = *stack_b->head;
		i = min_cost_ba(stack_a, stack_b);
		while (i >= 0)
		{
			if (i == sim_rot_number_a(stack_a, stack_b, tmp->number))
				i = apply_rarb(stack_a, stack_b, tmp->number, 'b');
			else if (i == sim_revrot_number_a(stack_a, stack_b, tmp->number))
				i = apply_rrarrb(stack_a, stack_b, tmp->number, 'b');
			else if (i == rarrb_number_a(stack_a, stack_b, tmp->number))
				i = apply_rarrb(stack_a, stack_b, tmp->number, 'b');
			else if (i == rrarb_number_a(stack_a, stack_b, tmp->number))
				i = apply_rrarb(stack_a, stack_b, tmp->number, 'b');
			else
			 tmp = tmp->next;
		}
	}
}
