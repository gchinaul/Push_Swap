/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:49:20 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 11:49:23 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = get_last_node(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stacks *stacks, int print)
{
	rotate(&stacks->a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stacks *stacks, int print)
{
	rotate(&stacks->b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stacks *stacks, int print)
{
	rotate(&stacks->a);
	rotate(&stacks->b);
	if (print)
		write(1, "rr\n", 3);
}
