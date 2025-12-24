/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:29:30 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 14:03:24 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*find_max_node(t_node *stack)
{
	t_node	*max;

	max = stack;
	while (stack)
	{
		if (stack->value > max->value)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

void	sort_three(t_stacks *stacks)
{
	t_node	*max;

	max = find_max_node(stacks->a);
	if (max == stacks->a)
		ra(stacks, 1);
	else if (max == stacks->a->next)
		rra(stacks, 1);
	if (stacks->a->value > stacks->a->next->value)
		sa(stacks, 1);
}
