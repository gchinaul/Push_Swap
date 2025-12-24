/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:22:54 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 13:30:49 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_node	*find_min_node(t_node *stack)
{
	t_node	*min;

	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

static t_node	*find_smallest_bigger(t_node *stack_a, int value_b)
{
	t_node	*target;
	t_node	*current;

	target = NULL;
	current = stack_a;
	while (current)
	{
		if (current->value > value_b)
		{
			if (!target || current->value < target->value)
				target = current;
		}
		current = current->next;
	}
	return (target);
}

void	assign_index(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
}

void	find_target_nodes(t_node *stack_a, t_node *stack_b)
{
	t_node	*current_b;
	t_node	*target;

	current_b = stack_b;
	while (current_b)
	{
		target = find_smallest_bigger(stack_a, current_b->value);
		if (!target)
			target = find_min_node(stack_a);
		current_b->target = target;
		current_b = current_b->next;
	}
}
