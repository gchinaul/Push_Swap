/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:48:46 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 11:48:49 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stacks *stacks, int print)
{
	swap(&stacks->a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks, int print)
{
	swap(&stacks->b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stacks *stacks, int print)
{
	swap(&stacks->a);
	swap(&stacks->b);
	if (print)
		write(1, "ss\n", 3);
}
