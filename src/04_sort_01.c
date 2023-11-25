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
