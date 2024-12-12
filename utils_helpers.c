/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:12:24 by rgriffit          #+#    #+#             */
/*   Updated: 2024/12/06 17:15:41 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_target(t_stack *stack)
{
	t_node	*current;
	int		max_target;

	if (stack->top == NULL)
		return (-1);
	current = stack->top;
	max_target = current->target;
	while (current)
	{
		if (current->target > max_target)
			max_target = current->target;
		current = current->next;
	}
	return (max_target);
}

int	find_max(t_stack *stack)
{
	t_node	*current;
	int		max_value;

	if (stack == NULL || stack->top == NULL)
		return (INT_MIN);
	current = stack->top;
	max_value = current->value;
	while (current != NULL)
	{
		if (current->value > max_value)
			max_value = current->value;
		current = current->next;
	}
	return (max_value);
}

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min_value;

	if (stack == NULL || stack->top == NULL)
		return (INT_MAX);
	current = stack->top;
	min_value = current->value;
	while (current)
	{
		if (current->value < min_value)
			min_value = current->value;
		current = current->next;
	}
	return (min_value);
}

long	handle_sign(const char **arg)
{
	long	sign;

	sign = 1;
	if (**arg == '-')
	{
		sign = -1;
		(*arg)++;
	}
	else if (**arg == '+')
	{
		(*arg)++;
	}
	return (sign);
}

long	ft_atol(const char *arg)
{
	long	result;
	long	sign;

	result = 0;
	if (!arg || !*arg)
		ft_error(NULL, NULL);
	while (*arg == ' ' || (*arg >= '\t' && *arg <= '\r'))
		arg++;
	sign = handle_sign(&arg);
	while (*arg >= '0' && *arg <= '9')
	{
		if (result > (LONG_MAX / 10) || (result == (LONG_MAX / 10)
				&& (*arg - '0') > (LONG_MAX % 10)))
			ft_error(NULL, NULL);
		result = result * 10 + (*arg - '0');
		arg++;
	}
	if (*arg && (*arg < '0' || *arg > '9'))
		ft_error(NULL, NULL);
	return (result * sign);
}
