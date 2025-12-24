/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:25:17 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 15:22:57 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

static void	parse_and_add_split(t_stacks *stack, char **split_args)
{
	int	j;

	j = 0;
	while (split_args[j])
	{
		if (parse_and_add(stack, split_args[j]))
		{
			free_split(split_args);
			free_stack(&stack->a);
			free_stack(&stack->b);
			error_exit(stack);
		}
		j++;
	}
}

void	init_stack(t_stacks *stack, int argc, char **argv)
{
	char	**split_args;
	int		i;

	i = 1;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		if (!split_args || !split_args[0])
		{
			free_split(split_args);
			free_stack(&stack->a);
			free_stack(&stack->b);
			error_exit(stack);
		}
		parse_and_add_split(stack, split_args);
		free_split(split_args);
		i++;
	}
	check_duplicates(stack, stack->a);
}

uint16_t	fast_stack_size(t_node *stack)
{
	uint16_t	size;

	size = 0;
	while (stack && ++size)
		stack = stack->next;
	return (size);
}

void	free_stack(t_node **stack)
{
	t_node	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
