/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_input_processing_01.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:47:48 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/24 14:50:17 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	update_meta(t_stack *stack)
{
	t_inode	*last;

	stack->size = lstsize(stack->head);
	stack->tail = get_tail(stack->head);
	stack->min = (*stack->head)->number;
	stack->max = (*stack->head)->number;
	if (stack->size == 1)
	{
		stack->tail = *stack->head;
		return ;
	}
	last = *stack->head;
	while (last->next != *stack->head)
	{
		if (last->number < stack->min)
			stack->min = last->number;
		if (last->number > stack->max)
			stack->max = last->number;
		last = last->next;
	}
	if (last->number < stack->min)
		stack->min = last->number;
	if (last->number > stack->max)
		stack->max = last->number;
}

t_inode	*get_tail(t_inode **head)
{
	t_inode	*last;

	if ((*head)->next == *head)
		return (*head);
	last = *head;
	while (last->next != *head)
		last = last->next;
	return (last);
}

unsigned int	lstsize(t_inode **head)
{
	unsigned int	size;
	t_inode	*last;

	if (*head == NULL)
		return (0);
	size = 1;
	last = *head;
	if ((*head)->next == *head)
		return (size);
	while (last->next != *head)
	{
		size++;
		last = last->next;
	}
	return (size);
}
