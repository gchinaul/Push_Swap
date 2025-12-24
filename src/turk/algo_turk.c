/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:36:26 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 14:23:09 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * push -> B
 * trie 3 elem dans A
 * B != 0 alors :
 * index
 * target B
 * couts
 * noeuds pas cher
 * exec
 * min au top final
 */

void	turk_algorithm(t_stacks *stacks)
{
	t_node	*cheapest;

	while (stacks->size_a > 3)
	{
		pb(stacks, 1);
		stacks->size_a--;
		stacks->size_b++;
	}
	sort_three(stacks);
	while (stacks->b)
	{
		assign_index(stacks->a);
		assign_index(stacks->b);
		find_target_nodes(stacks->a, stacks->b);
		calculate_costs(stacks, stacks->b);
		cheapest = find_cheapest_node(stacks->b);
		if (cheapest && cheapest->target)
			execute_cheapest_move(stacks, cheapest);
	}
	assign_index(stacks->a);
	rotate_to_min(stacks);
}
