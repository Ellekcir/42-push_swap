#include "push_swap.h"

// takes two arguments as input ./push_swap "1, 4, 6, 8"
// error handling - only two arguments
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
// Initialises stacks a and b
	a = create_stack();
	b = create_stack();
// Take input arguments and push them to stack a
	if (!input_args(a, argc, argv))
		exit_error();
	if (is_sorted(a))
		return (0);
	if (a->size <= 5)
		sort_small(a, b);
	else
		sort_large(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}