/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:09:01 by rgriffit          #+#    #+#             */
/*   Updated: 2024/12/06 16:09:20 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Searches through stack for the minimum value
// When found using its index it will see which 
// will get it to the top of stack with the least 
// amount of moves then once the rotations are 
// done will push it to stack b
static void	push_smallest_a_to_b(t_stack *a, t_stack *b)
{
	int		min;
	int		index;
	t_node	*current;

	min = find_min(a);
	index = 0;
	current = a->top;
	while (current && current->value != min)
	{
		current = current->next;
		index++;
	}
	if (index <= a->size / 2)
	{
		while (index-- > 0)
			ra(a);
	}
	else
	{
		while (index++ < a->size)
			rra(a);
	}
	pb(a, b);
}

// This will push all the elements from stack b to a
// back in order as it will be pushing all the values back
// the correct order
static void	push_all_back_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
		pa(a, b);
}

// Sorts the medium-sized stack using Insertion Sort logic
// Pushes all but 3 in smallest to largest order to stack b
// Sorts the remaining three before pushing all back to a
void	sort_medium(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		push_smallest_a_to_b(a, b);
	sort_small(a);
	push_all_back_to_a(a, b);
}
