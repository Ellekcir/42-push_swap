#include "push_swap.h"

int ft_issorted(t_stack *stack)
{
	t_node	*current;
	ft_printf("\n----- CHECKING STACK IS SORTED -----\n");	
	
    if (!stack || !stack->top || !stack->top->next)
	{
		ft_printf("Stack is empty or is a single-node stack therefore is sorted\n");
		return (0);
	}
	current = stack->top;
    while (current->next != NULL) 
	{        
		ft_printf("Comparing top node value: %d", current->value);
		ft_printf(" to the top's next node value: %d\n", current->next->value);
        if ( current->next->value < current->value)
		{
			ft_printf("Stack is NOT sorted\n\n");
			return (1);
		}
        current = current->next;
    }
	ft_printf("Stack is already sorted\n");
    return (0);
}

int	ft_isint(const char *arg)
{
		long	number;

		ft_printf("----Checking argument %s if it is an integer\n", arg);
		if (*arg == '\0')
			return (1);
		if (*arg == '-' || *arg == '+')
			arg++;
		while (*arg != '\0')
		{
			if (!ft_isdigit(*arg))
				return (1);
			arg++;
		}
		number = ft_atoi(arg);
		if ((number > INT_MAX) || (number < INT_MIN))
			ft_error("Arguments are out of Integer range");
		return (0);
}

int	ft_isdup(char **argv)
{
	int	i;
	int	next_i;

	ft_printf("CHECKING FOR DUPLICATES\n");
	i = 0;		
	while (argv[i])
	{
		next_i = i + 1;
		ft_printf("----Checking argument: %s for duplicate\n",argv[i]);
		while (argv[next_i])
		{	
			if (ft_strcmp(argv[i], argv[next_i]) == 0)
			{
				ft_printf("FOUND DUPLICATE: %s\n",argv[next_i]);
				return (1);
			}	
			next_i++;
		}
		i++;
	}
	return (0);
}

void	ft_check_args_are_valid(char **argv)
{
	int i;
		// int j;
	ft_printf("------ VALIDATING INPUT ------\n\n");
	if (argv == NULL || *argv == NULL)
		ft_error("No arguments found\n");
	if (ft_isdup(argv) == 1)
			ft_error("A Duplicate was found\n");
	i = 0;
    ft_printf("CHECKING FOR INPUT TYPE\n");
	while (argv[++i])
	{
		if (ft_isint(argv[i]) == 1)
			ft_error("Invalid input type, please use integers only\n");
	}
	ft_printf("\nNo duplicates or invalid input types found\n");

}