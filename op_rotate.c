/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:14:53 by rgriffit          #+#    #+#             */
/*   Updated: 2024/12/06 10:15:03 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack *a)
{
	if (a && a->size > 1)
	{
		ft_rotate(a);
		ft_printf("ra\n");
	}
}

void	rb(t_stack *b)
{
	if (b && b->size > 1)
	{
		ft_rotate(b);
		ft_printf("rb\n");
	}
}

void	rr(t_stack *a, t_stack *b)
{
	if (a && b && a->size > 1 && b->size > 1)
	{
		ft_rotate(a);
		ft_rotate(b);
		ft_printf("rr\n");
	}
}
