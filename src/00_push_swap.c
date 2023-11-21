/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:27:41 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/21 12:55:50 by iusantos         ###   ########.fr       */
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
	t_stack	stack_a;
	t_stack	stack_b;
	t_inode	**og_head;

	if (argc == 1)
		exit(1);
	stack_a.head = ft_calloc(1, sizeof(t_inode *));
	stack_b.head = ft_calloc(1, sizeof(t_inode *));
	process_input(argc, argv, &stack_a);
	ft_printf("Is ordered? %d\n", is_ordered(stack_a.head));
	if (is_ordered(stack_a.head))
	{
		destroy_list(stack_a.head);
		exit(0);
	}
	sort(&stack_a, &stack_b);
	og_head = ft_calloc(1, sizeof(t_inode *));
	destroy_list(stack_a.head);
	free(stack_a.head);
	free(og_head);
}
