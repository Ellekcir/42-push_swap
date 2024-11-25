#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = create_stack();
	b = create_stack();
	if (!a || !b)
	{
		ft_error(a, b);
	}
	if (argc < 2)
	{
		free_stack(&a);
		free_stack(&b);
		exit (0);
	}
	parse_input(a, b, argv, argc);
	if (!is_sorted(a))
		push_swap(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
