/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:27:41 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/14 19:00:16 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//returns 1 if str is a "proper" int, disregarding range. 0 otherwise
int	is_int(char *str)
{
	if (!*str || !str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		else
			str++;
	}
	return (1);
}

//returns 0 if out of int range
int is_in_range(long long nbr)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	else
		return (1);
}

//create a node
t_inode	*create_node(int number)
{
	t_inode	*new_node;

	new_node = (t_inode *) malloc(sizeof(t_inode));
	if (new_node == NULL)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	new_node->prev = NULL;
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
		(*head)->prev = new_node;
		return;
	}
	last = *head;
	while(last->next != *head)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	new_node->next = *head;
	(*head)->prev = new_node;
}

//check if a number is already contained in a linked-list
int	is_dup(int number, t_inode **head)
{
	t_inode	*current;

	if (*head == NULL)
		return (0);
	current = *head;
	while (current->next != *head)
	{
		if (current->number == number)
			return (1);
		current = current->next;
	}
	if (current->number == number)
		return (1);
	else
		return (0);
}

void	destroy_list(t_inode **head)
{
	t_inode	*og_head;

	og_head = *head;
	while ((*head)->next != og_head)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
}

int main(int argc, char *argv[])
{
	int	i = 1;
	t_inode	**head;
	t_inode	**head_og;

	if (argc == 1)
		exit(1);
	head = ft_calloc(1, sizeof(t_inode *));
	//so adiciona à lista se for proper_int - refatorar depois.
	while(i < argc)
	{
		if (is_int(argv[i]) && is_in_range(ft_atoll(argv[i])) && !is_dup(ft_atoi(argv[i]), head))
			append_node(head, create_node(ft_atoi(argv[i])));
		else
		{
			ft_putstr_fd("Error\n", 2);
			destroy_list(head);
			free(head);
			exit(1);
		}
		i++;
	}
	head_og = ft_calloc(1, sizeof(t_inode *));
	*head_og = *head;
	while((*head)->next != *head_og)
	{
		ft_printf("number: %d\n", (*head)->number);
		*head = (*head)->next;
	}
	ft_printf("number: %d\n", (*head)->number);
}
