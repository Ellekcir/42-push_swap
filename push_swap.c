#include "push_swap.h"
#include <stdio.h>



int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	char **split_args;
	int	arg;

	a = create_stack();
	b = create_stack();
	if (argc < 2)
		ft_error("No arguments provided");
	ft_printf("Input has been detected\n");
	if (argc == 2)
	{
		split_args = ft_split(argv[1], ' ');
		if (!split_args || !split_args[0])
            ft_error("Invalid input or empty split");
		ft_check_args_are_valid(split_args);
		arg = 0;
		while (split_args[arg])
		{
			put_value_to_stack(a, ft_atoi(split_args[arg]));
			ft_printf("A value of: %i is the new stack size\n", a->size);
			arg++;
		}
		while (arg > 0)
		{
			free(split_args[arg]);
			arg--;
		}
		free(split_args);
	}
	else
	{
		ft_check_args_are_valid(argv);
		ft_printf("Arguments have been checked if they are valid input\n");
		arg = argc - 1;
		ft_printf("Arguments now will be pushed to the stack\n");
		while (arg > 0)
		{
			put_value_to_stack(a, ft_atoi(argv[arg]));
			ft_printf("A value of: %i is the new stack size\n", a->size);
			arg--;
		}
	}
	ft_issorted(a);
	print_stack(a);
	if (a->size <= 5)
		sort_five_or_less(a, b);
	else
		sort_radix(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}

