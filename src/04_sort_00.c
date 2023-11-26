/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_sort_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:56:35 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/24 15:03:06 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_ordered(t_inode **head)
{
	t_inode	*og_head;

	og_head = *head;
	while (og_head->next != *head)
	{
		if (og_head->next->number < og_head->number)
			return (0);
		og_head = og_head->next;
	}
	return (1);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		sort_two(stack_a);
		return;
	}
	if (stack_a->size == 3)
	{
		sort_three(stack_a);
		return;
	}
	push(stack_a->head, stack_b->head);
	push(stack_a->head, stack_b->head);
	ft_printf("pb\n");
	ft_printf("pb\n");
	update_meta(stack_a);
	update_meta(stack_b);
	proper_push_b(stack_a, stack_b);
}

//preciso pensar melhor onde colocar as chamadas para o ft_printf
void	sort_two(t_stack *stack)
{
	if (is_ordered(stack->head))
		return;
	swap(stack->head, 0);
}

void	sort_three(t_stack *stack)
{
	if ((*stack->head)->number == stack->min)
	{
		swap(stack->head, 0);
		rot(stack->head, 0);
		update_meta(stack);
	}
	else if ((*stack->head)->number == stack->max)
	{
		rot(stack->head, 0);
		if (!is_ordered(stack->head))
			swap(stack->head, 0);
		update_meta(stack);
	}
	else
	{
		if (get_index(stack->head, stack->max) == 1)
			rrot(stack->head, 0);
		else
			swap(stack->head, 0);
		update_meta(stack);
	}
}

//return the index of a number in a linked-list
unsigned int	get_index(t_inode **head, int nbr)
{
	unsigned int	index;
	t_inode		*tmp;
	index = 0;
	tmp = *head;
	while (tmp->number != nbr)
	{
		index++;
		tmp = tmp->next;
	}
	(*head)->index = 0; //n sei pq
	return (index);
}
