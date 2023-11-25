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

//pega o menor numero de rotacoes
int	sim_rot_number(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	unsigned int i;

	i = get_insert_index(stack_b, nbr);
	if (i < get_index(stack_a->head, nbr))
		i = get_index(stack_a->head, nbr);
	return (i);
}

//pega o menor numero de rotacoes reversas
int	sim_revrot_number(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	unsigned int i;

	i = 0;
	if (get_insert_index(stack_b, nbr) != 0)
		i = stack_b->size - get_insert_index(stack_b, nbr);
	if ((i < stack_a->size - get_index(stack_a->head, nbr)) && get_index(stack_a->head, nbr))
		i = stack_a->size - get_index(stack_a->head, nbr);
	return (i);
}
