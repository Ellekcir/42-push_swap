#include "push_swap.h"

long	ft_atol(const char *arg)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	if (!arg || !*arg)
		ft_error(NULL, NULL);
	while (*arg == ' ' || (*arg >= '\t' && *arg <= '\r'))
		arg++;
	if (*arg == '-' || *arg == '+')
		sign = (*arg++ == '-') ? -1 : 1;
	while (*arg >= '0' && *arg <= '9')
	{
		if (result > (LONG_MAX / 10) || 
			(result == (LONG_MAX / 10) && (*arg - '0') > (LONG_MAX % 10)))
			ft_error(NULL, NULL);
		result = result * 10 + (*arg - '0');
		arg++;
	}
	if (*arg && (*arg < '0' || *arg > '9'))
		ft_error(NULL, NULL);
	return (result * sign);
}


int	is_valid_int(const char *arg)
{
	int	sign_count;

	sign_count = 0;
	if (!arg || !*arg)
		ft_error(NULL, NULL);
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

int has_duplicates(t_stack *a)
{
	t_node *current_node;
	t_node *next_node;

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

int is_sorted(t_stack *stack)
{
	t_node *current_node;

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
