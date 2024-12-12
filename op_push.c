/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:12:52 by rgriffit          #+#    #+#             */
/*   Updated: 2024/12/06 10:12:53 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *from, t_stack *to)
{
	t_node	*temp;

	if (!to || !from || from->size == 0)
		ft_error(from, to);
	temp = from->top;
	from->top = from->top->next;
	temp->next = to->top;
	to->top = temp;
	from->size--;
	to->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	if (!a || !b)
		ft_error(a, b);
	ft_push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		ft_error(a, b);
	ft_push(a, b);
	ft_printf("pb\n");
}
