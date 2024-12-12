/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:35:30 by rgriffit          #+#    #+#             */
/*   Updated: 2024/12/06 11:48:43 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(const char *arg)
{
	int	sign_count;

	sign_count = 0;
	if (!arg || !*arg)
		return (0);
	while (*arg == ' ' || (*arg >= '\t' && *arg <= '\r'))
		arg++;
	if (*arg == '-' || *arg == '+')
	{
		sign_count++;
		arg++;
	}
	if (!*arg || !ft_isdigit(*arg))
		return (0);
	while (*arg)
	{
		if (!ft_isdigit(*arg++))
			return (0);
	}
	return (sign_count <= 1);
}

int	is_in_range(const char *arg)
{
	long	number;

	number = ft_atol(arg);
	return (number >= INT_MIN && number <= INT_MAX);
}

int	has_duplicates(t_stack *a)
{
	t_node	*current_node;
	t_node	*next_node;

	if (!a || !a)
		return (0);
	current_node = a->top;
	while (current_node)
	{
		next_node = current_node->next;
		while (next_node != NULL)
		{
			if (current_node->value == next_node->value)
				return (1);
			next_node = next_node->next;
		}
		current_node = current_node->next;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current_node;

	if (!stack || !stack->top || !stack->top->next)
		return (1);
	current_node = stack->top;
	while (current_node->next != NULL)
	{
		if (current_node->value > current_node->next->value)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}
