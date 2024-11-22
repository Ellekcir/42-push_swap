#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc < 2)
		return (0);
	a = create_stack();
	b = create_stack();
	if (!a || !b)
	{
		return (1);
	}
	parse_input(a, b, argv, argc);
	if (!ft_issorted(a))
		push_swap(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
