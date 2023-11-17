/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_motions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:09:29 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/17 17:30:31 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_inode **head)
{
	t_inode *first;
	t_inode	*second;
	t_inode	*last;

	if (*head == NULL || (*head)->next == *head)
		return ;
	first = *head;
	second = first->next;
	last = *head;
	while (last->next != *head)
		last = last->next;
	if (last->next->next == last)
	{
		first->next = second;
		second->next = first;
		*head = second;
		return ;
	}
	first->next = second->next;
	second->next = first;
	*head = second;
	last->next = *head;
}
