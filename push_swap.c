#include "push_swap.h"

void push_swap(t_stack *a, t_stack *b) 
{
	if (a->size <= 3)
		sort_small(a);
	else if (a->size <= 20)
		sort_medium(a, b);
	else if (a->size > 20)
	 	sort_large(a, b);
//	print_stack(a);
}
