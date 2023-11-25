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
	stack_b->size = 0;
}

//preciso pensar melhor onde colocar as chamadas para o ft_printf
void	sort_two(t_stack *stack)
{
	if (is_ordered(stack->head))
		return;
	swap(stack->head);
}

void	sort_three(t_stack *stack)
{
	if ((*stack->head)->number == stack->min)
	{
		swap(stack->head);
		rot(stack->head);
		update_meta(stack);
	}
	else if ((*stack->head)->number == stack->max)
	{
		rot(stack->head);
		if (!is_ordered(stack->head))
			swap(stack->head);
		update_meta(stack);
	}
	else
	{
		if (get_index(stack->head, stack->max) == 1)
			rrot(stack->head);
		else
			swap(stack->head);
		update_meta(stack);
	}
}

//return the index of a number in a linked-list
unsigned int	get_index(t_inode **head, int nbr)
{
	unsigned int	index;
	index = 0;
	while ((*head)->number != nbr)
	{
		index++;
		(*head) = (*head)->next;
	}
	(*head)->index = 0; //n sei pq
	return (index);
}
