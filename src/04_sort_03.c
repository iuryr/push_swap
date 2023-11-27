/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_sort_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:55:01 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/27 11:59:13 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rrarb_number_a(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	unsigned int	i;

	i = 0;
	if (get_insert_index(stack_a, nbr))
		i = stack_a->size - get_insert_index(stack_a, nbr);
	i = i + get_index(stack_b->head, nbr);
	return (i);
}

void	final_ordering(t_stack *s)
{
	unsigned int	i;

	i = get_index(s->head, s->min);
	if (i < s->size - i)
	{
		while ((*s->head)->number != s->min)
			rot(s, 0);
	}
	else
	{
		while ((*s->head)->number != s->min)
			rrot(s, 0);
	}
}
