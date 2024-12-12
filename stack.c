/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:41:55 by rgriffit          #+#    #+#             */
/*   Updated: 2024/12/06 16:11:58 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		ft_error(NULL, NULL);
	new_node->value = value;
	new_node->target = -1;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*create_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		ft_error(NULL, NULL);
	new_stack->top = NULL;
	new_stack->size = 0;
	return (new_stack);
}

void	put_value_to_stack(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*current_node;

	if (!stack)
		ft_error(stack, NULL);
	new_node = create_node(value);
	if (!new_node)
		ft_error(stack, NULL);
	if (stack->size == 0)
		stack->top = new_node;
	else
	{
		current_node = stack->top;
		while (current_node->next)
			current_node = current_node->next;
		current_node->next = new_node;
	}
	stack->size++;
}

void	free_nodes_from_stack(t_stack *stack)
{
	t_node	*top_node;

	if (!stack || !stack->top)
		ft_error(stack, NULL);
	top_node = stack->top;
	stack->top = top_node->next;
	free(top_node);
	stack->size--;
}

void	free_stack(t_stack **stack)
{
	if (!stack || !(*stack))
		ft_error(*stack, NULL);
	while ((*stack)->size > 0)
		free_nodes_from_stack(*stack);
	free(*stack);
	*stack = NULL;
}
