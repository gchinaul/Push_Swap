/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:01:10 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 13:21:07 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	double_rot(t_stacks *stacks, t_node *cheapest, bool user_rr,
		bool user_rrr)
{
	uint16_t	i;
	uint16_t	max_combined;

	i = 0;
	if (cheapest->cost_a < cheapest->cost_b)
		max_combined = cheapest->cost_a;
	else
		max_combined = cheapest->cost_b;
	while (i < max_combined && (user_rr || user_rrr))
	{
		if (user_rr)
			rr(stacks, 1);
		else
			rrr(stacks, 1);
		assign_index(stacks->a);
		assign_index(stacks->b);
		i++;
	}
}

static t_node	*find_min_node_and_index(t_stacks *stacks, int *min_index)
{
	t_node	*min;
	t_node	*current;

	if (!stacks->a)
		return (NULL);
	min = stacks->a;
	current = stacks->a;
	*min_index = 0;
	while (current)
	{
		if (current->value < min->value)
		{
			min = current;
			*min_index = current->index;
		}
		current = current->next;
	}
	return (min);
}

void	execute_cheapest_move(t_stacks *stacks, t_node *cheapest)
{
	bool	use_rr;
	bool	use_rrr;

	if (!cheapest || !cheapest->target)
		return ;
	assign_index(stacks->a);
	assign_index(stacks->b);
	use_rr = (cheapest->flags & FLAG_SAME_DIR)
		&& (cheapest->flags & FLAG_ROTATE_UP);
	use_rrr = (cheapest->flags & FLAG_SAME_DIR)
		&& (cheapest->flags & FLAG_ROTATE_DOWN);
	double_rot(stacks, cheapest, use_rr, use_rrr);
	bring_to_top_a(stacks, cheapest->target);
	bring_to_top_b(stacks, cheapest);
	pa(stacks, 1);
	update_stack_sizes(stacks);
}

void	rotate_to_min(t_stacks *stacks)
{
	t_node	*min;
	int		min_index;
	int		size;

	if (!stacks->a)
		return ;
	min = find_min_node_and_index(stacks, &min_index);
	size = stack_size(stacks->a);
	assign_index(stacks->a);
	while (stacks->a != min)
	{
		if (min_index <= size / 2)
			ra(stacks, 1);
		else
			rra(stacks, 1);
	}
}
