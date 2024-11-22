#include "push_swap.h"

void	ft_push(t_stack *from, t_stack *to)
{
	t_node	*temp;

	if (!to || !from || from->size == 0)
		ft_error(from, to);
	temp = from->top;
	from->top = from->top->next;
	temp->next = to->top;
	to->top = temp;
	from->size--;
	to->size++;
}

void	ft_pa(t_stack *a, t_stack *b)
{
	if (!a || !b)
		ft_error(a, b);
	ft_push(b, a);
	ft_printf("pa\n");
}

void	ft_pb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		ft_error(a, b);
	ft_push(a, b);
	ft_printf("pb\n");
}
