#include "push_swap.h"

// REVERSE ROTATE
// Reverse rotate the stack 
// (move the bottom element to the top)
void	ft_rev_rotate(t_stack *stack)
{
	t_node	*temp;
	t_node	*prev;

	if (stack->size < 2)
		return ;
	temp = stack->top;
	while (temp->next->next)
		temp = temp->next;
	prev = temp;
	temp = temp->next;

	prev->next = NULL;
	temp->next = stack->top;
	stack->top = temp;
}
// Moves the bottom of Stack A to the top.
void	ft_rra(t_stack *a)
{ 
	ft_rev_rotate(a);
	ft_printf("rra\n");
}
// Moves the bottom of Stack B to the top.
void	ft_rrb(t_stack *b)
{
	ft_rev_rotate(b);
	ft_printf("rrb\n");
}
// Simultaneously reverse rotates both Stacks A and B
void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	ft_printf("rrr\n");
}