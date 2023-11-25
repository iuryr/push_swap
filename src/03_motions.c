/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_motions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:09:29 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/21 11:11:30 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_inode **head, int flag)
{
	t_inode	*first;
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
	if (flag == 0)
		ft_printf("sa\n");
}

void	rot(t_inode **head, int flag)
{
	*head = (*head)->next;
	if (flag == 0)
		ft_printf("ra\n");
	if (flag == 2)
		ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rot(stack_a->head, 2);
	rot(stack_b->head, 2);
	ft_printf("rr\n");

}

void	rrot(t_inode **head, int flag)
{
	t_inode	*og_head;

	og_head = *head;
	if ((*head)->next == *head)
		return ;
	while (og_head->next != *head)
		og_head = og_head->next;
	*head = og_head;
	if (flag == 0)
		ft_printf("rra\n");
}

void	push(t_inode **from, t_inode **to)
{
	t_inode	*last;
	t_inode	*old_first;

	if (*from == NULL)
		return ;
	old_first = *from;
	last = *from;
	if (old_first->next == old_first)
	{
		prepend_node(to, old_first);
		*from = NULL;
		return ;
	}
	while (last->next != *from)
		last = last->next;
	last->next = (*from)->next;
	*from = (*from)->next;
	prepend_node(to, old_first);
}
