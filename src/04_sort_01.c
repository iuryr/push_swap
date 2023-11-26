#include "../include/push_swap.h"

int	get_insert_index(t_stack *stack, int nbr)
{
	unsigned int i;
	t_inode *tmp;

	if (nbr > (*stack->head)->number && nbr < stack->tail->number)
		return (0);
	if (nbr > stack->max || nbr < stack->min)
		return (get_index(stack->head, stack->max));
	i = 1;
	tmp = (*stack->head);
	while (nbr > tmp->number || nbr < tmp->next->number)
	{
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

//numero total de operacoes
int	rarrb_number(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	unsigned int i;

	i = 0;
	if (get_insert_index(stack_b, nbr))
		i = stack_b->size - get_insert_index(stack_b, nbr);
	i = i + get_index(stack_a->head, nbr);
	return (i);
}

//numero total de operacoes
int	rrarb_number(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	unsigned int i;

	i = 0;
	if (get_index(stack_a->head, nbr))
		i = stack_a->size - get_index(stack_a->head, nbr);
	i = i + get_insert_index(stack_b, nbr);
	return (i);
}
