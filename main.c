#include "push_swap.h"

// Checks if inout has been given
// Initiates stacks
// Parses the input to stack a
// Sorts the input through our push swap function
// Frees memory of the stacks when done

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc < 2)
		return (0);
	a = create_stack();
	b = create_stack();
	parse_input(a, b, argv, argc);
	if (!ft_issorted(a))
		push_swap(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
