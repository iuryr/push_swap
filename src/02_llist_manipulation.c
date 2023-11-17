/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_llist_manipulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:48:38 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/17 19:45:51 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//create a node
t_inode	*create_node(int number)
{
	t_inode	*new_node;

	new_node = (t_inode *) malloc(sizeof(t_inode));
	if (new_node == NULL)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}

//add a node to the end of the linked-list
void	append_node(t_inode **head, t_inode *new_node)
{
	t_inode	*last;

	if (*head == NULL)
	{
		*head = new_node;
		(*head)->next = new_node;
		return ;
	}
	last = *head;
	while (last->next != *head)
		last = last->next;
	last->next = new_node;
	new_node->next = *head;
}

void	prepend_node(t_inode **head, t_inode *new_node)
{
	t_inode	*old_first;
	t_inode	*last;

	if (*head == NULL)
	{
		*head = new_node;
		(*head)->next = new_node;
		return ;
	}
	old_first = *head;
	new_node->next = old_first;
	*head = new_node;
	last = *head;
	if ((*head)->next->next == old_first)
	{
		old_first->next = *head;
		return ;
	}
	while (last->next != old_first)
		last = last->next;
	last->next = *head;
}

void	destroy_list(t_inode **head)
{
	t_inode	*og_head;
	t_inode	*temp;

	if (*head == NULL)
		return ;
	og_head = *head;
	while ((*head)->next != og_head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	free(*head);
}
