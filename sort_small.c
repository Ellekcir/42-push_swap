#include "push_swap.h"

// Sort two elements
void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		swap(a);
}

// Sort three elements
void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second > third)
	{
		swap(a);
		reverse_rotate(a);
	}
	if (first > second && first < third)
		swap(a);
	if (first > third)
		rotate(a);
	if (second > first && second < third)
		reverse_rotate(a);
	if (second > third)
		rotate(a);
}
/*
123 
132 s 312 r 123
213 s 123
231 rr 123
312 r 123
321 s 231 rr 123
*/

// Sort four or five elements - uses selection sort/push/pop
void	sort_small(t_stack *a, t_stack *b)
{
	int	min;

	min = find_min(a);
	while (a->size > 3)
	{
		while (a->top->value != min)
			rotate(a);
		push(a, b);
	}
	sort_three(a);
	while (b->size)
		push(b, a);
}