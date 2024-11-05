#include "push_swap.h"

// PUSH
// Pushes the top element from one stack to another
// & updates the stacks new size
// (stack A = 'from', stack B = 'to' or vise versa)
void	ft_push(t_stack *from, t_stack *to)
{
	t_node	*temp;

	if (!from || from->size == 0)
		return ;
	temp = from->top;
	from->top = from->top->next;
	temp->next = to->top;
	to->top = temp;

	from->size--;
	to->size++;
}

// Pushes first element of stack B and puts it at the top of Stack A
void	ft_pa(t_stack *a, t_stack *b)
{
	ft_push(b, a);
	ft_printf("pa\n");
}
// Pushes the first element of Stack A and put it at top of Stack B
void	ft_pb(t_stack *a, t_stack *b)
{
	ft_push(a, b);
	ft_printf("pb\n");
}