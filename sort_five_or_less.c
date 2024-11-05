#include "push_swap.h"

// Sort two elements
void	sort_two(t_stack *a)
{
	ft_printf("\n ### sort_two ###\n");
	if (a->top->value > a->top->next->value)
		ft_sa(a);
}

// Sort three elements
void	sort_three(t_stack *a)
{
	ft_printf("\n ### sort_three ###\n");
	int	first;
	int	second;
	int	third;

	if (a->size != 3)
		return ;
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;

	if (first < second && first < third) // 132
	{
		ft_sa(a); //312
		ft_ra(a); //123
	}
	else if (first > second && second > third) //321
	{
		ft_sa(a); //231
		ft_rra(a);
	}
	else if (first < third && second < third) // 213
		ft_sa(a); // 123
	else if (first < second) //231
		ft_rra(a);
	else if (first > second) //312
		ft_ra(a);
}

int find_min(t_stack *stack)
{
	t_node *current;
	int min;

	if (stack == NULL || stack->top == NULL)
		return (0);
	current = stack->top;
	min = current->value;
	while (current != NULL)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}
// Sort four or five elements - uses selection sort/push/pop
void	sort_five_or_less(t_stack *a, t_stack *b)
{
	int	min;
	
	ft_printf("\n ----- ENTERING SORT FIVE OR LESS ----- \n");
	ft_printf("\n -----Stack A - Size and values before SMALL SORT \nSize: %i\n", a->size);
	print_stack(a);
	ft_printf("\n -----Stack B - Size and values before SMALL SORT \nSize: %i\n", b->size);
	print_stack(b);
	min = find_min(a);
	if (a->size == 2)
		sort_two(a);
	if (a->size == 3)
		sort_three(a);
	while (a->size > 3)
	{
		while (a->top->value != min)
			ft_ra(a);
		ft_pb(a, b);
		min = find_min(a);
		ft_printf("Stack A Size in loop SMALL SORT %i\n", a->size);
		ft_printf("Stack B Size in loop  SMALL SORT %i\n", b->size);
	}
	
	
	while (b->size > 0)
	{
		ft_printf("Stack A Size in loop SMALL SORT %i\n", a->size);
		ft_printf("Stack B Size in loop  SMALL SORT %i\n", b->size);
		ft_pa(b, a);
	}
	ft_printf("\n -----Stack A:\n");
	print_stack(a);
	ft_printf("\n -----Stack B:\n");
	print_stack(b);
}

	// 123 SORTED
	// 132 FIRST < SECOND FIRST < THIRD  SA 312 RA 123
	// 231 FIRST < SECOND FIRST > THIRD RRA 123 
	// 213 FIRST > SECOND FIRST < THIRD SA 123 ---
	// 312 FIRST > SECOND FIRST > THIRD RA 123 ---
	// 321 FIRST > SECOND  SECOND > THIRD SA 231 RRA 123 --- 