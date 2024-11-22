// #include "push_swap.h"
// // This will swap two integers
// void ft_swap(int *a, int *b)
// {
// 	int temp;
	
// 	temp = *a;
// 	*a = *b;
// 	*b = temp;
// }

// // Partition function for QuickSort
// int partition(int array[], int low, int high)
// {
// 	int pivot = array[high]; // Choosing the last element as the pivot
// 	int i = low - 1;	   // Index of smaller element

// 	if (low >= high)
// 	{
// 		return i + 1; // base case: return the index for the partition
// 	}

// 	if (array[low] < pivot)
// 	{							  // If the current element is smaller than the pivot
// 		i++;					  // Increment the smaller element index
// 		swap(&array[i], &array[low]); // Swap elements
// 	}

// 	partition(array, low + 1, high); // Recursively partition the rest of the array

// 	swap(&array[i + 1], &array[high]); // Move the pivot to its correct position
// 	return (i + 1);				   // Return the pivot index
// }

// // QuickSort function to sort the array
// void quickSort(int array[], int low, int high)
// {
// 	if (low < high)
// 	{
// 		int pi = partition(array, low, high); // Partition the array and get the pivot index
// 		quickSort(array, low, pi - 1);		// Left of pivot
// 		quickSort(array, pi + 1, high);		// Right of pivot
// 	}
// }

// // Recursive function to find the index of a value in the array
// int find_index_recursive(int array[], int size, int value, int index)
// {
// 	if (index >= size)
// 	{
// 		return -1; // Base case: value not found
// 	}
// 	if (array[index] == value)
// 	{
// 		return index; // Return the index if value matches
// 	}
// 	return find_index_recursive(array, size, value, index + 1); // Recursive call to check the next index
// }

// // Function to assign target index based on the sorted order
// void assign_targets(t_stack *stack)
// {
// 	int **array;
// 	int i;
// 	t_node *temp;

// 	i = 0;
// 	temp = stack->top;
// 	array = (int *)malloc(sizeof(int *) * stack->size);

	
// 	void fill_array(t_node * node, int index)
// 	{
// 		if (node == NULL)
// 			return;
// 		array[index] = node->value;
// 		fill_array(node->next, index + 1);
// 	}

// 	fill_array(stack->top, 0); // Populate the array with values

// 	// Sort the array using QuickSort
// 	quickSort(array, 0, stack->size - 1);

// 	// Assign the target index based on the sorted array
// 	temp = stack->top;
// 	while (temp != NULL)
// 	{
// 		int index = find_index_recursive(array, stack->size, temp->value, 0);
// 		temp->target = index; // Assign the target index
// 		temp = temp->next;
// 	}

// 	// Free the allocated memory for the array
// 	free(array);
// }

// // Helper function to print the stack
// void print_stack(t_stack *stack)
// {
// 	t_node *temp = stack->top;
// 	while (temp)
// 	{
// 		printf("Value: %d, Target: %d\n", temp->value, temp->target);
// 		temp = temp->next;
// 	}
// }
