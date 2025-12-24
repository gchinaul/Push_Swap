/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:49:51 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 11:49:54 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	second_last = NULL;
	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	second_last->next = NULL;
}

void	rra(t_stacks *stacks, int print)
{
	reverse_rotate(&stacks->a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stacks *stacks, int print)
{
	reverse_rotate(&stacks->b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stacks *stacks, int print)
{
	reverse_rotate(&stacks->a);
	reverse_rotate(&stacks->b);
	if (print)
		write(1, "rrr\n", 4);
}
