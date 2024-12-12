/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:40:51 by rgriffit          #+#    #+#             */
/*   Updated: 2024/12/06 16:19:01 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = create_stack();
	b = create_stack();
	if (!a || !b)
	{
		ft_error(a, b);
	}
	if (argc < 2)
	{
		free_stack(&a);
		free_stack(&b);
		exit (0);
	}
	parse_input(a, b, argv, argc);
	if (!is_sorted(a))
		push_swap(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
