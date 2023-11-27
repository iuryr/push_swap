/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_motions_02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:55:18 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/27 11:44:27 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	min_cost_ab(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_inode	*tmp;

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
		tmp = tmp->next;
	}
	i = check_last(stack_a, stack_b, tmp, i);
	return (i);
}

int	min_cost_ba(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_inode	*tmp;

	tmp = *stack_b->head;
	i = sim_revrot_number_a(stack_a, stack_b, (*stack_b->head)->number);
	while (tmp->next != *stack_b->head)
	{
		if (i > sim_rot_number_a(stack_a, stack_b, tmp->number))
			i = sim_rot_number_a(stack_a, stack_b, tmp->number);
		if (i > sim_revrot_number_a(stack_a, stack_b, tmp->number))
			i = sim_revrot_number_a(stack_a, stack_b, tmp->number);
		if (i > rarrb_number_a(stack_a, stack_b, tmp->number))
			i = rarrb_number_a(stack_a, stack_b, tmp->number);
		if (i > rrarb_number_a(stack_a, stack_b, tmp->number))
			i = rrarb_number_a(stack_a, stack_b, tmp->number);
		tmp = tmp->next;
	}
	i = check_last_a(stack_a, stack_b, tmp, i);
	return (i);
}

void	proper_push_b(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_inode	*tmp;

	while (stack_a->size > 3 && !is_ordered(stack_a))
	{
		tmp = *stack_a->head;
		i = min_cost_ab(stack_a, stack_b);
		while (i >= 0)
		{
			if (i == sim_rot_number(stack_a, stack_b, tmp->number))
				i = apply_rarb(stack_a, stack_b, tmp->number, 'a');
			else if (i == sim_revrot_number(stack_a, stack_b, tmp->number))
				i = apply_rrarrb(stack_a, stack_b, tmp->number, 'a');
			else if (i == rarrb_number(stack_a, stack_b, tmp->number))
				i = apply_rarrb(stack_a, stack_b, tmp->number, 'a');
			else if (i == rrarb_number(stack_a, stack_b, tmp->number))
				i = apply_rrarb(stack_a, stack_b, tmp->number, 'a');
			else
				tmp = tmp->next;
		}
	}
}

void	proper_push_a(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_inode	*tmp;

	while (*stack_b->head)
	{
		tmp = *stack_b->head;
		i = min_cost_ba(stack_a, stack_b);
		while (i >= 0)
		{
			if (i == sim_rot_number_a(stack_a, stack_b, tmp->number))
				i = apply_rarb(stack_a, stack_b, tmp->number, 'b');
			else if (i == sim_revrot_number_a(stack_a, stack_b, tmp->number))
				i = apply_rrarrb(stack_a, stack_b, tmp->number, 'b');
			else if (i == rarrb_number_a(stack_a, stack_b, tmp->number))
				i = apply_rarrb(stack_a, stack_b, tmp->number, 'b');
			else if (i == rrarb_number_a(stack_a, stack_b, tmp->number))
				i = apply_rrarb(stack_a, stack_b, tmp->number, 'b');
			else
				tmp = tmp->next;
		}
	}
}

void	print_push(int c)
{
	if (c == 0)
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
}
