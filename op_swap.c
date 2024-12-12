/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:15:19 by rgriffit          #+#    #+#             */
/*   Updated: 2024/12/06 10:15:35 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	sa(t_stack *a)
{
	if (a && a->size > 1)
	{
		ft_swap(a);
		ft_printf("sa\n");
	}
}

void	sb(t_stack *b)
{
	if (b && b->size > 1)
	{
		ft_swap(b);
		ft_printf("sb\n");
	}
}

void	ss(t_stack *a, t_stack *b)
{
	if ((a && a->size > 1) && (b && b->size > 1))
	{
		ft_swap(a);
		ft_swap(b);
		ft_printf("ss\n");
	}
}
