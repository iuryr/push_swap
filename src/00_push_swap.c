/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:27:41 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/15 14:52:37 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_inode	**head;
	t_inode	**head_og;

	if (argc == 1)
		exit(1);
	head = ft_calloc(1, sizeof(t_inode *));
	process_input(argc, argv, head);
	head_og = ft_calloc(1, sizeof(t_inode *));
	*head_og = *head;
	while ((*head)->next != *head_og)
	{
		ft_printf("number: %d\n", (*head)->number);
		*head = (*head)->next;
	}
	ft_printf("number: %d\n", (*head)->number);
	destroy_list(head);
	free(head);
	free(head_og);
}
