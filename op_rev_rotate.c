/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:13:12 by rgriffit          #+#    #+#             */
/*   Updated: 2024/12/06 10:14:39 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_stack *stack)
{
	t_node	*temp;
	t_node	*prev;

	if (stack->size < 2)
		return ;
	temp = stack->top;
	while (temp->next->next)
		temp = temp->next;
	prev = temp;
	temp = temp->next;
	prev->next = NULL;
	temp->next = stack->top;
	stack->top = temp;
}

void	rra(t_stack *a)
{
	ft_rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	ft_rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	ft_printf("rrr\n");
}
