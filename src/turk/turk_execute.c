/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:57:24 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 13:11:42 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	bring_to_top_a(t_stacks *stacks, t_node *node)
{
	int	size;

	size = stack_size(stacks->a);
	while (stacks->a != node)
	{
		if (node->index <= size / 2)
			ra(stacks, 1);
		else
			rra(stacks, 1);
		assign_index(stacks->a);
	}
}

void	bring_to_top_b(t_stacks *stacks, t_node *node)
{
	int	size;

	size = stack_size(stacks->b);
	while (stacks->b != node)
	{
		if (node->index <= size / 2)
			rb(stacks, 1);
		else
			rrb(stacks, 1);
		assign_index(stacks->b);
	}
}
