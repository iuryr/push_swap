/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:27:41 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/21 16:10:13 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		exit(1);
	stack_a.head = ft_calloc(1, sizeof(t_inode *));
	stack_b.head = ft_calloc(1, sizeof(t_inode *));
	process_input(argc, argv, &stack_a);
	if (is_ordered(&stack_a))
	{
		destroy_list(stack_a.head);
		exit(0);
	}
	sort(&stack_a, &stack_b);
	destroy_list(stack_a.head);
	free(stack_a.head);
	free(stack_b.head);
	return (0);
}
