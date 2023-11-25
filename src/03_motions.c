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

void	swap(t_inode **head, int flag)
{
	t_inode	*first;
	t_inode	*second;
	t_inode	*last;

	if (*head == NULL || (*head)->next == *head)
		return ;
	first = *head;
	second = first->next;
	last = *head;
	while (last->next != *head)
		last = last->next;
	if (last->next->next == last)
	{
		first->next = second;
		second->next = first;
		*head = second;
		return ;
	}
	first->next = second->next;
	second->next = first;
	*head = second;
	last->next = *head;
	if (flag == 0)
		ft_printf("sa\n");
}

void	rot(t_inode **head, int flag)
{
	*head = (*head)->next;
	if (flag == 0)
		ft_printf("ra\n");
	if (flag == 1)
		ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rot(stack_a->head, 2);
	rot(stack_b->head, 2);
	ft_printf("rr\n");
}

void	rrot(t_inode **head, int flag)
{
	t_inode	*og_head;

	og_head = *head;
	if ((*head)->next == *head)
		return ;
	while (og_head->next != *head)
		og_head = og_head->next;
	*head = og_head;
	if (flag == 0)
		ft_printf("rra\n");
	if (flag == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rrot(stack_a->head, 2);
	rrot(stack_b->head, 2);
	ft_printf("rrr\n");
}

void	push(t_inode **from, t_inode **to)
{
	t_inode	*last;
	t_inode	*old_first;

	if (*from == NULL)
		return ;
	old_first = *from;
	last = *from;
	if (old_first->next == old_first)
	{
		prepend_node(to, old_first);
		*from = NULL;
		return ;
	}
	while (last->next != *from)
		last = last->next;
	last->next = (*from)->next;
	*from = (*from)->next;
	prepend_node(to, old_first);
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
