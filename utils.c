#include "push_swap.h"

void	ft_error(char *s)
{
	write(2, "Error:\n", 7);
	ft_printf("%s", s);
	exit (1);
}

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2)) 
	{
		
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int is_empty(t_stack *stack)
{
    return (stack == NULL || stack->size == 0);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

    if (!stack || !stack->top)
    {
        ft_printf("Stack is empty.\n");
        return ;
    }
	current = stack->top;
	while (current != NULL)
	{
		ft_printf("\n%i", current->value);
		current = current->next;
	}
}

