#include "push_swap.h"
// SWAP
// Swap the first two elements in the stack 
void	swap(t_stack *stack)
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

// PUSH
// Pushes the top element from one stack to another
// & updates the stacks new size
// (stack A = 'from', stack B = 'to' or vise versa)
void	push(t_stack *from, t_stack *to)
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

// ROTATE
// Rotate the stack 
// move top elemnet to the bottom
void	rotate(t_stack *stack)
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

// ROTATE
// rotate the stack 
// move the top element to the bottom
void	rotate(t_stack *stack)
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

// REVERSE ROTATE
// Reverse rotate the stack 
// (move the bottom element to the top)
void	reverse_rotate(t_stack *stack)
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
