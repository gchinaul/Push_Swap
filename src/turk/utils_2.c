/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:31:09 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 14:22:38 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	set_rotation_flags(t_stacks *stacks, t_node *stack_b)
{
	t_node		*current_b;
	uint16_t	half_a;
	uint16_t	half_b;

	half_a = stacks->size_a >> 1;
	half_b = stacks->size_b >> 1;
	current_b = stack_b;
	while (current_b)
	{
		current_b->flags = 0;
		if (current_b->index <= half_b)
			current_b->flags |= FLAG_ROTATE_UP;
		else
			current_b->flags |= FLAG_ROTATE_DOWN;
		if (current_b->target->index <= half_a)
			current_b->flags |= FLAG_ROTATE_UP_A;
		else
			current_b->flags |= FLAG_ROTATE_DOWN_A;
		current_b = current_b->next;
	}
}

static void	set_node_costs(t_stacks *stacks, t_node *stack_b)
{
	t_node		*current_b;
	uint16_t	half_a;
	uint16_t	half_b;

	half_a = stacks->size_a >> 1;
	half_b = stacks->size_b >> 1;
	current_b = stack_b;
	while (current_b)
	{
		if (current_b->index <= half_b)
			current_b->cost_b = current_b->index;
		else
			current_b->cost_b = stacks->size_b - current_b->index;
		if (current_b->target->index <= half_a)
			current_b->cost_a = current_b->target->index;
		else
			current_b->cost_a = stacks->size_a - current_b->target->index;
		current_b = current_b->next;
	}
}

void	calculate_costs(t_stacks *stacks, t_node *stack_b)
{
	t_node	*current_b;
	bool	rotate_up_b;
	bool	rotate_up_a;

	set_rotation_flags(stacks, stack_b);
	set_node_costs(stacks, stack_b);
	current_b = stack_b;
	while (current_b)
	{
		rotate_up_b = (current_b->flags & FLAG_ROTATE_UP) != 0;
		rotate_up_a = (current_b->flags & FLAG_ROTATE_UP_A) != 0;
		if (rotate_up_a == rotate_up_b)
		{
			current_b->flags |= FLAG_SAME_DIR | FLAG_OPTIMIZABLE;
			if (current_b->cost_a > current_b->cost_b)
				current_b->total_cost = current_b->cost_a;
			else
				current_b->total_cost = current_b->cost_b;
		}
		else
			current_b->total_cost = current_b->cost_a + current_b->cost_b;
		current_b = current_b->next;
	}
}

t_node	*find_cheapest_node(t_node *stack_b)
{
	t_node	*cheapest;
	t_node	*current;

	if (!stack_b)
		return (NULL);
	cheapest = stack_b;
	current = stack_b->next;
	while (current)
	{
		if (current->total_cost < cheapest->total_cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
