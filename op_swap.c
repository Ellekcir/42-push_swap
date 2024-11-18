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

void	ft_sa(t_stack *a)
{
	ft_swap(a);
	ft_printf("sa\n");
}

void	ft_sb(t_stack *b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}