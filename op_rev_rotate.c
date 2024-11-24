#include "push_swap.h"

void	ft_rev_rotate(t_stack *stack) 
{
	t_node	*temp;
	t_node	*prev;

	if (stack->size < 2)
		return;
	temp = stack->top;
	while (temp->next->next)
		temp = temp->next;
	prev = temp;
	temp = temp->next;

	prev->next = NULL;
	temp->next = stack->top;
	stack->top = temp;
}

void	ft_rra(t_stack *a)
{
	ft_rev_rotate(a);
	ft_printf("rra\n");
	print_stack(a);
}

void	ft_rrb(t_stack *b)
{
	ft_rev_rotate(b);
	ft_printf("rrb\n");
	print_stack(b);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	ft_printf("rrr\n");
}