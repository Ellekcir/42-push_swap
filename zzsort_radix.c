#include "push_swap.h"

int	find_max(t_stack *stack)
{
	t_node	*temp;
	int		max_value;

	temp = stack->top;
	max_value = temp->index;
	while (temp != NULL)
	{
		if (temp->index > max_value)
			max_value = temp->index;
		temp = temp->next;
	}
	return (max_value);
}

// void ft_assign_target_position(t_stack *stack)
// {
// 	t_node *current;
// 	int min_value;
// 	int index;

// 	if (stack == NULL || stack->top == NULL)
// 		return ;
// 	current = stack->top;
// 	min_value = current->value;
	
// 	while (current != NULL)
// 	{
// 		index = -1;
// 		while (current->value < min_value)
// 		{
// 			min_value = current->value;
// 			current->target_index = current->index + 1;
// 		}
		
// 		current = current->next;
// 		ft_printf("\n\n\nAssigning target value: %i", current->target_index);
// 		ft_printf("\nto node: %i\n", current->value);
// 	}
// }

// // void	assign_target_values(t_stack *a)
// // {
// // 	t_node	*current;

// // }	t_node	*compare;
// // 	int	target_index;

// // 	if (a == NULL || a->size == 0)
// // 		return ;
// // 	current = a->top;
// // 	while (current != NULL)
// // 	{
// // 		target_index = 0;
// // 		compare = a->top;
// // 		while (compare != NULL)
// // 		{
// // 			if (current->value > compare->value)
// // 				target_index++;
// // 			compare = compare->next;
// // 		}
// // 		current->target_value = target_index;
// // 		current = current->next;
// // 		ft_printf("\n\n\nAssigning target value: %i", current->target_value);
// // 		ft_printf("\nto node: %i\n", current->value);
// // 	}

void	assign_index_value(t_stack *a, int i, int minimum)
{
	t_node	*temp;

	temp = a->top;
	while (temp != NULL)
	{
		if (temp->value < minimum && temp->target_index == -1)
			temp->target_index = i;
		temp = temp->next;
	}
} 

void	index_value(t_stack *a)
{
	int minimum;
	int size;
	int	i;
	t_node *temp;

	i = 0;
	size = a->size;
	minimum = a->top->value;
	temp = a->top;
	while (i < size)
	{
		while (temp != NULL)
		{
			if (temp->value < minimum && temp->target_index == -1)
				minimum = temp->value;
			temp = temp->next;
		}
		assign_index_value(a, i, minimum);
		temp = a->top;
		while (temp != NULL)
		{
			if (temp->value < minimum && temp->target_index == -1)
				minimum = temp->value;
			temp = temp->next;
		}
		temp = a->top;
		i++;
	}
}


// void	sort_radix(t_stack *a, t_stack *b)
// {
// 	int	i;
// 	int	j;
// 	int	size;
// 	int	target;

// 	i = 0;
// 	size = a->size;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			target = a->top->target_index;
// 			if (((target >> i) & 1) == 1)
// 				ft_ra(a);
// 			else
// 				ft_pb(a, b);
// 			j++;
// 		}
// 		while (!is_empty(b))
// 			ft_pa(a, b);
// 		i++;
// 	}
// }
