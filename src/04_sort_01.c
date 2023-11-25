#include "../include/push_swap.h"

int	get_insert_index(t_stack *stack, int nbr)
{
	unsigned int i;
	t_inode *tmp;
	t_inode	*head;

	if (nbr > (*stack->head)->number && nbr < (*stack->tail)->number)
		return (0);
	if (nbr > stack->max || nbr < stack->min)
		return (get_index(stack->head, stack->max));
	i = 1;
	tmp = (*stack->head)->next;
	head = *stack->head;
	while (nbr > head->number || nbr < tmp->number)
	{
		head = tmp;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	sim_rot_number(t_stack *stack_a, t_stack *stack_b, int c)
{
	unsigned int i;

	i = get_insert_index(stack_b, c);
	if (i < get_index(stack_a->head, c))
		i = get_index(stack_a->head, c);
	return (i);
}
