/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_sort_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:52:35 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/27 11:58:33 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

unsigned int	get_index(t_inode **head, int nbr)
{
	unsigned int	index;
	t_inode			*tmp;

	index = 0;
	tmp = *head;
	while (tmp->number != nbr)
	{
		index++;
		tmp = tmp->next;
	}
	(*head)->index = 0;
	return (index);
}

int	get_insert_index_a(t_stack *a, int nbr)
{
	int		i;
	t_inode	*tmp;

	i = 1;
	if (nbr < (*a->head)->number && nbr > a->tail->number)
		return (0);
	if (nbr > a->max || nbr < a->min)
		return (get_index(a->head, a->min));
	tmp = (*a->head);
	while (tmp->number > nbr || tmp->next->number < nbr)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

//numero total de operacoes
int	rarrb_number(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	unsigned int	i;

	i = 0;
	if (get_insert_index(stack_b, nbr))
		i = stack_b->size - get_insert_index(stack_b, nbr);
	i = i + get_index(stack_a->head, nbr);
	return (i);
}

int	rarrb_number_a(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	unsigned int	i;

	i = 0;
	if (get_index(stack_b->head, nbr))
		i = stack_b->size - get_insert_index(stack_b, nbr);
	i = i + get_insert_index(stack_a, nbr);
	return (i);
}

//numero total de operacoes
int	rrarb_number(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	unsigned int	i;

	i = 0;
	if (get_index(stack_a->head, nbr))
		i = stack_a->size - get_index(stack_a->head, nbr);
	i = i + get_insert_index(stack_b, nbr);
	return (i);
}
