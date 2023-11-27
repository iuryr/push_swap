/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_motions_00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:09:29 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/27 10:05:22 by iusantos         ###   ########.fr       */
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
