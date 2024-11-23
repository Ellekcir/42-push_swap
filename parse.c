#include "push_swap.h"

static void	ft_handle_string_args(t_stack *a, t_stack *b, char *arg)
{
	char	**split_args;
	int		value;
	int		i;

	i = 0;
	split_args = ft_split(arg, ' ');
	if (!split_args || !split_args[0])
	{
		free(split_args);
		ft_error(a, b);
	}
	while (split_args[i])
	{
		value = ft_isint(split_args[i]);
		if (!value)
		{
			free(split_args[i]);
			while (split_args[++i])
				free(split_args[i]);
			free(split_args);
			ft_error(a, b);
		}
		put_value_to_stack(a, value);
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

void free_split(char **split_args)
{
    int i = 0;
    while (split_args[i])
    {
        free(split_args[i]);
        i++;
    }
    free(split_args);
}

static void	ft_handle_args(t_stack *a, t_stack *b, char **argv, int argc)
{
	int		i;
	int		value;

	if (argc < 2)
		ft_error(a, b);

	i = 1;
	while (i < argc)
	{
		value = ft_isint(argv[i]);
		if (!value)
			ft_error(a, b);
		put_value_to_stack(a, value);
		++i;
	}
}

void parse_input(t_stack *a, t_stack *b, char **argv, int argc)
{
	if (argc == 2)
		ft_handle_string_args(a, b, argv[1]);
	else
		ft_handle_args(a, b, argv, argc);
	if (ft_isdup(a) == 0)
		ft_error(a, b);
}