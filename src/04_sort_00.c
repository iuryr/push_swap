/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_sort_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:56:35 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/27 11:53:05 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_ordered(t_stack *s)
{
	t_inode	*og_head;

	og_head = *s->head;
	while (og_head->next != *s->head)
	{
		if (og_head->next->number < og_head->number)
			return (0);
		og_head = og_head->next;
	}
	return (1);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_a->size == 2)
	{
		sort_two(stack_a);
		return ;
	}
	if (stack_a->size == 3)
	{
		sort_three(stack_a);
		return ;
	}
	i = 0;
	while (stack_a->size > 3 && !is_ordered(stack_a) && i < 2)
	{
		push(stack_a, stack_b, 0);
		i++;
	}
	proper_push_b(stack_a, stack_b);
	if (stack_a->size == 3 && !is_ordered(stack_a))
		sort_three(stack_a);
	proper_push_a(stack_a, stack_b);
	final_ordering(stack_a);
}

void	sort_two(t_stack *stack)
{
	if (is_ordered(stack))
		return ;
	swap(stack, 0);
	ft_printf("sa\n");
}

void	sort_three(t_stack *stack)
{
	if (is_ordered(stack))
		return ;
	if ((*stack->head)->number == stack->min)
	{
		swap(stack, 0);
		rot(stack, 0);
		update_meta(stack);
	}
	else if ((*stack->head)->number == stack->max)
	{
		rot(stack, 0);
		if (!is_ordered(stack))
			swap(stack, 0);
	}
	else
	{
		if (get_index(stack->head, stack->max) == 1)
			rrot(stack, 0);
		else
			swap(stack, 0);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if ((*a->head)->number == a->min || (*a->head)->number == a->max)
			push(a, b, 0);
		else
			rot(a, 0);
	}
	sort_three(a);
	while (*b->head)
	{
		if ((*b->head)->number > (*b->head)->next->number)
		{
			push(b, a, 1);
			rot(a, 0);
		}
		push(b, a, 1);
	}
}
