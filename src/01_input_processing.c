/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_input_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:45:20 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/21 12:40:40 by iusantos         ###   ########.fr       */
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
int	is_in_range(long long nbr)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	else
		return (1);
}

//returns 1 if number is already in a list's node, 0 otherwise
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

void	process_input(int argc, char *argv[], t_stack *stack)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_int(argv[i]) && is_in_range(ft_atoll(argv[i]))
			&& !is_dup(ft_atoi(argv[i]), stack->head))
			append_node(stack->head, create_node(ft_atoi(argv[i])));
		else
		{
			ft_putstr_fd("Error\n", 2);
			destroy_list(stack->head);
			free(stack->head);
			exit(1);
		}
		i++;
	}
	stack->size = argc - 1;
	set_minmax(stack);
	update_minmax(stack);
}

void	set_minmax(t_stack *stack)
{
	stack->min = (*stack->head)->number;
	stack->max = (*stack->head)->number;
}

void	update_minmax(t_stack *stack)
{
	t_inode	*last;

	if (stack->size == 1)
		return;
	last = *stack->head;
	while (last->next != *stack->head)
	{
		if (last->number < stack->min)
			stack->min = last->number;
		if (last->number > stack->max)
			stack->max = last->number;
		last = last->next;
	}
	if (last->number < stack->min)
		stack->min = last->number;
	if (last->number > stack->max)
		stack->max = last->number;
}
