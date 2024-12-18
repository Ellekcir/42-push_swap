/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:09:38 by rgriffit          #+#    #+#             */
/*   Updated: 2024/12/06 16:10:29 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->size == 2 && a->top->value > a->top->next->value)
		sa(a);
}

void	sort_three(t_stack *a)
{
	t_node	*first;
	t_node	*second;
	int		max_value;

	if (a->size != 3)
		ft_error(a, NULL);
	max_value = find_max(a);
	first = a->top;
	second = first->next;
	if (first->value == max_value)
		ra(a);
	else if (second->value == max_value)
		rra(a);
	first = a->top;
	second = first->next;
	if (first->value > second->value)
		sa(a);
}

void	sort_small(t_stack *a)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
}
