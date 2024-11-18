#include "push_swap.h"

static void	ft_handle_string_args(t_stack *a, t_stack *b, char *arg)
{
	char	**split_args;
	int	value;
	int	i;

	i = 0;
	split_args = ft_split(&arg[0], ' ');
	if (!split_args || !split_args[0])
	{
	//	ft_printf("Failure to split args");
		ft_error(a, b);
	}
	while (split_args[i])
	{

		value = ft_isint(split_args[i]);
	//	ft_printf("Split value: %d\n", value);
		put_value_to_stack(a, value);
		free(split_args[i]);
		++i;
	}
	free(split_args);
}

static void	ft_handle_args(t_stack *a, t_stack *b, char **argv, int argc)
{
	int	i;
	int value;

	i = 1;
	if (argc < 2)
		ft_error(a, b);
	while (i < argc)
	{
		value = ft_isint(argv[i]);
		put_value_to_stack(a, value);
		++i;
	}
}

void parse_input(t_stack *a, t_stack *b, char **argv, int argc)
{
//	ft_printf("ARGC: %d\n",argc);
	if (argc == 2)
		ft_handle_string_args(a, b, argv[1]);
	else
		ft_handle_args(a, b, argv, argc);
//	print_stack(a);
	if (ft_isdup(a) == 0)
	{
//		ft_printf("Duplicate found");
		ft_error(a, b);
	}
}	