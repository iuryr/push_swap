/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_motions_03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:39:09 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/27 11:45:15 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_last(t_stack *stack_a, t_stack *stack_b, t_inode *tmp, int x)
{
	int	i;

	i = x;
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

int	check_last_a(t_stack *stack_a, t_stack *stack_b, t_inode *tmp, int x)
{
	int	i;

	i = x;
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
