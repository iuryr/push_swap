/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:27:41 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/15 17:56:21 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_ordered(t_inode **head)
{
	t_inode	*og_head;

	og_head = *head;
	while ((*head)->next != og_head)
	{
		if ((*head)->next->number < (*head)->number)
			return (0);
		*head = (*head)->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_inode	**stack_a;
	t_inode	**og_head;

	if (argc == 1)
		exit(1);
	stack_a = ft_calloc(1, sizeof(t_inode *));
	process_input(argc, argv, stack_a);
	ft_printf("Is ordered? %d\n", is_ordered(stack_a));
	if (is_ordered(stack_a))
	{
		destroy_list(stack_a);
		exit(0);
	}
	og_head = ft_calloc(1, sizeof(t_inode *));
	*og_head = *stack_a;
	while ((*stack_a)->next != *og_head)
	{
		ft_printf("number: %d\n", (*stack_a)->number);
		*stack_a = (*stack_a)->next;
	}
	ft_printf("number: %d\n", (*stack_a)->number);
	ft_printf("\n");
	*stack_a = *og_head;
	swap(stack_a);
	*og_head = *stack_a;
	while ((*stack_a)->next != *og_head)
	{
		ft_printf("number: %d\n", (*stack_a)->number);
		*stack_a = (*stack_a)->next;
	}
	ft_printf("number: %d\n", (*stack_a)->number);
	destroy_list(stack_a);
	free(stack_a);
	free(og_head);
}
