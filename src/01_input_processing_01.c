/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_input_processing_01.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:47:48 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/21 12:49:57 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	update_minmax(t_stack *stack)
{
	t_inode	*last;

	if (stack->size == 1)
		return ;
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
