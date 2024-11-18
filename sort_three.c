#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->size == 2 && a->top->value > a->top->next->value)
		ft_sa(a);
}

void	sort_three(t_stack *a)
{
	int	max_value;

	if (a->size != 3)
		return ;
	max_value = find_max(a);
	if (max_value == a->top->value)
		ft_ra(a);
	else if (max_value == a->top->next->value)
		ft_rra(a);
	if (a->top->value > a->top->next->value)
		ft_sa(a);
}

void	sort_small(t_stack *a)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
}