/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:15:48 by rgriffit          #+#    #+#             */
/*   Updated: 2024/12/06 10:17:00 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split_args)
{
	int	i;

	i = 0;
	if (!split_args)
		ft_error(NULL, NULL);
	while (split_args[i])
		free(split_args[i++]);
	free(split_args);
}

void	handle_string_args(t_stack *a, t_stack *b, char *arg)
{
	char	**split_args;
	int		i;
	int		value;

	split_args = ft_split(arg, ' ');
	if (!split_args || !split_args[0])
	{
		free_split(split_args);
		exit (0);
	}
	i = 0;
	while (split_args[i])
	{
		if (!is_valid_int(split_args[i]) || !is_in_range(split_args[i]))
		{
			free_split(split_args);
			ft_error(a, b);
		}
		value = ft_atol(split_args[i++]);
		put_value_to_stack(a, value);
	}
	free_split(split_args);
}

void	handle_args(t_stack *a, t_stack *b, char **argv, int argc)
{
	int	i;
	int	value;

	i = 1;
	if (argc == 1)
		exit (0);
	while (i < argc)
	{
		if (!is_valid_int(argv[i]) || !is_in_range(argv[i]))
			ft_error(a, b);
		value = ft_atol(argv[i]);
		put_value_to_stack(a, value);
		i++;
	}
}

void	parse_input(t_stack *a, t_stack *b, char **argv, int argc)
{
	if (!a || !b)
		ft_error(a, b);
	if (argc == 2)
		handle_string_args(a, b, argv[1]);
	else
		handle_args(a, b, argv, argc);
	if (has_duplicates(a))
		ft_error(a, b);
	if (is_sorted(a))
		exit(0);
}
