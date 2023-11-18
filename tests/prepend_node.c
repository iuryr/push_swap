#include "../include/push_swap.h"

void print_list(t_inode **head)
{
	t_inode *og_head;

	og_head = *head;
	while (og_head->next != *head)
	{
		ft_printf("number: %d\n", og_head->number);
		og_head = og_head->next;
	}
	ft_printf("number: %d\n\n", og_head->number);
	
}

int main(void)
{
	t_inode **head;

	head = ft_calloc(1, sizeof(t_inode *));
	prepend_node(head, create_node(100));
	print_list(head);
	prepend_node(head, create_node(200));
	print_list(head);
	prepend_node(head, create_node(300));
	print_list(head);
	prepend_node(head, create_node(400));
	print_list(head);
	prepend_node(head, create_node(500));
	print_list(head);
	prepend_node(head, create_node(600));
	print_list(head);
}
