/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:19:45 by rgriffit          #+#    #+#             */
/*   Updated: 2024/12/12 20:59:22 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Finds the very last element (bottom node) in the stack.
t_node	*get_last_node(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	while (current->next)
		current = current->next;
	return (current);
}

/*
Rotates stack a to move a specific elements using the "target" value to the top
If the specific target is closer to the top, it rotates upwards.
If the specific target is closer to the bottom, it reverse rotates downwards.
It also checks if the second stack (b) needs to be rotated at the same time
for efficiency.
*/
static void	rotation(t_stack *a, t_stack *b, t_node	*b_last_node,
int target_position)
{
	if (target_position <= a->size / 2)
	{
		while (target_position > 0)
		{
			if (b->size > 2 && b->top->target < b->top->next->target)
				rr(a, b);
			else
				ra(a);
			target_position--;
		}
	}
	else
	{
		while (target_position < a->size)
		{
			if (b->size > 2 && b->top->target < b_last_node->target)
				rrr(a, b);
			else
				rra(a);
			target_position++;
		}
	}
}

/*
Moves specific elements using the "target" value to the top stack a 
and then pushes it to stack b. First, it figures out how to rotate 
stack a to get the target to the top. Then it uses a helper function
to do the rotation and pushes the element to stack b.
*/
void	rotate_and_push(t_stack *a, t_stack *b, int target_position)
{
	t_node	*b_last_node;

	b_last_node = get_last_node(b);
	rotation(a, b, b_last_node, target_position);
	pb(a, b);
}

/*
Figures out how far a specific element determined by its "target" value
is from the top of the stack. It calculates the number of steps needed 
to get the target block to the top. If it's quicker to rotate forward, 
it returns a positive number. If it's quicker to rotate backward, it returns a
negative number. If the block isn’t found, it returns -1.
*/
int	distance_to_target(t_stack *stack, int target)
{
	t_node	*current;
	int		position;

	if (stack->top == NULL)
		return (-1);
	current = stack->top;
	position = 0;
	while (current != NULL)
	{
		if (current->target == target)
			break ;
		current = current->next;
		position++;
	}
	if (current == NULL)
		return (-1);
	if (position <= stack->size / 2)
		return (position);
	return (position - stack->size);
}

/*
Moves all the elements from stack b back to stack a, one at a time.
It finds the element with the biggest number "max target" in stack b,
then rotates stack b to bring it to the top. It then pushes it back to
stack a. This repeats until stack b is empty.
*/
void	merge_chunks_back(t_stack *a, t_stack *b)
{
	int	max_target;
	int	distance;

	while (b->size > 0)
	{
		max_target = find_max_target(b);
		distance = distance_to_target(b, max_target);
		while (b->top->target != max_target)
		{
			if (distance > 0)
			{
				rb(b);
				distance--;
			}
			else
			{
				rrb(b);
				distance++;
			}
		}
		pa(a, b);
	}
}
