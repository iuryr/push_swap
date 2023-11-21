/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_sort_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:56:35 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/21 14:04:03 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		swap(stack_a->head);
		ft_printf("sa\n");
		return;
	}
	stack_b->size = 0;
}
