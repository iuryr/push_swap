/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:27:41 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/17 18:28:34 by iusantos         ###   ########.fr       */
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
	while ((*og_head)->next != *stack_a)
	{
		ft_printf("number: %d\n", (*og_head)->number);
		*og_head = (*og_head)->next;
	}
	ft_printf("number: %d\n", (*og_head)->number);
	ft_printf("\n");
	// swap(stack_a);
	// rot(stack_a);
	// rrot(stack_a);
	*og_head = *stack_a;
	while ((*og_head)->next != *stack_a)
	{
		ft_printf("number: %d\n", (*og_head)->number);
		*og_head = (*og_head)->next;
	}
	ft_printf("number: %d\n", (*og_head)->number);
	ft_printf("\n");
	destroy_list(stack_a);
	free(stack_a);
	free(og_head);
}
