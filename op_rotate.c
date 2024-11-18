#include "push_swap.h"

void	ft_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*temp;

	if (stack->size < 2)
		return ;
	first = stack->top;
	stack->top = stack->top->next;

	temp = stack->top;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
}

void	ft_ra(t_stack *a)
{
	ft_rotate(a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack *b)
{
	ft_rotate(b);
	ft_printf("rb\n");
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}