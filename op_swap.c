#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	sa(t_stack *a)
{
	if (a && a->size > 1)
	{
		ft_swap(a);
		ft_printf("sa\n");
		// print_stack(a);
	}
}

void	sb(t_stack *b)
{
	if (b && b->size > 1)
	{
		ft_swap(b);
		ft_printf("sb\n");
		// print_stack(b);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	if ((a && a->size > 1) && (b && b->size > 1))
	{
		ft_swap(a);
		ft_swap(b);
		ft_printf("ss\n");
	}
}
