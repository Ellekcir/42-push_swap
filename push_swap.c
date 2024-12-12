/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:17:21 by rgriffit          #+#    #+#             */
/*   Updated: 2024/12/06 10:22:42 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_targets(t_stack *a)
{
	t_node	*current;
	t_node	*min_node;
	int		index;
	int		min_value;

	if (!a)
		ft_error(a, NULL);
	index = 0;
	while (index < a->size)
	{
		current = a->top;
		min_value = INT_MAX;
		min_node = NULL;
		while (current)
		{
			if (current->target == -1 && current->value < min_value)
			{
				min_value = current->value;
				min_node = current;
			}
			current = current->next;
		}
		if (min_node)
			min_node->target = index++;
	}
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (!a || !b)
		ft_error(a, b);
	if (a->size <= 3)
		sort_small(a);
	else if (a->size <= 6)
		sort_medium(a, b);
	else
		sort_large(a, b);
}
