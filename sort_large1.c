/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:58:44 by rgriffit          #+#    #+#             */
/*   Updated: 2024/12/12 21:06:08 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Checks if the elements target value at the given index is closer to the 
top of the stack than the current minimum distance. If it is closer,
it updates the minimum distance and returns 1 (true). 
Otherwise, it returns 0 (false).
*/
int	is_target_closer(int index, int size, int *min_distance)
{
	int	distance;

	distance = index;
	if (index > size / 2)
		distance = size - index;
	if (distance < *min_distance)
	{
		*min_distance = distance;
		return (1);
	}
	return (0);
}

/*
Finds the closest target to the top of the Stack a. It will measure 
*/
int	find_closest_target(t_stack *a, int chunk_start, int chunk_size)
{
	t_node	*current;
	int		min_distance;
	int		target_position;
	int		i;

	current = a->top;
	min_distance = a->size;
	target_position = -1;
	i = 0;
	while (current != NULL)
	{
		if (current->target >= chunk_start
			&& current->target < chunk_start + chunk_size
			&& is_target_closer(i, a->size, &min_distance))
			target_position = i;
		current = current->next;
		i++;
	}
	return (target_position);
}

/*
This will take both stacks, pushing the elements from stack
a to b using the designated tagets in a chunk deteremined by
the the chunk_start and the chunk_size as it incremently
grabs a chunk at time in the sort_large function. This will
push each element of that designated chunk of elements and
choose which is closest rotating it to the top with a qualifying
'target' in the stack before making any operations and pushing
them to B.
*/
void	push_chunks_to_b(t_stack *a, t_stack *b,
int chunk_start, int chunk_size)
{
	int	pushed_count;
	int	target_position;

	pushed_count = 0;
	while (pushed_count < chunk_size && a->size > 0)
	{
		target_position = a->top->target;
		target_position = find_closest_target(a, chunk_start, chunk_size);
		if (target_position != -1)
		{
			rotate_and_push(a, b, target_position);
			pushed_count++;
		}
	}
}

/*
ft_chunk_size was created so that it will dynamically
deteremine the size of the chunks depending on the size
of the input given. This is done returning the stack size
if input is less than 10, the stacsize / 7 if the input
is between 10 and 100, otherwise it will divide the stack
size by 15 for 100+ elements. I chose these values after
testing and seeing what worked best to get the least operations.
*/
int	ft_chunk_size(int stack_size)
{
	if (stack_size <= 10)
		return (stack_size);
	if (stack_size <= 100)
		return (stack_size / 7);
	return (stack_size / 15);
}

/*
1.
sort_large is the main function that wiil sort the stack
It will use merge algorithm to sort the stack by dividing
it into chunks. 
I created chunks by determining the stack size which is 
essentually gathered from the input and depending on how 
many elements of input were given, depended on how many
chunks would be created to then individually use.
if the stack size was below 10, it would be sorted using
the medium sort using insertion sort algorithm, otherwise
it would be sorted using the large sort using merge sort
approach.
By doing it this way I assigned all elements a 'target' 
this value is that will be used to determine its position 
when it has been sorted, this allows the in put to have
many different values and still be sorted using positive
values only, these would be valued from 0 to the size of
the stack. When the stacks are created they given a default
'-1' value to each elements target eg: a->top->target == -1
before it is assigned value.
While the chunk_start-ing point is less than the stak_total
will keep pushing chunks of elements to stack B, these will
be insomewhat a mixed decending order order of the chunks using
the target value. 
If there is remaining of a chunk it will sort the rest using
insertion using sort_medium before then merging all elements
back to stack a in acending order of the element.
*/
void	sort_large(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	chunk_start;
	int	stack_total;

	stack_total = a->size;
	chunk_size = ft_chunk_size(a->size);
	chunk_start = 0;
	if (stack_total <= 10)
	{
		sort_medium(a, b);
		return ;
	}
	else
	{
		assign_targets(a);
		while (chunk_start < stack_total)
		{
			push_chunks_to_b(a, b, chunk_start, chunk_size);
			chunk_start += chunk_size;
		}
		if (a->size > 0)
			sort_medium(a, b);
	}
	merge_chunks_back(a, b);
}
