/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:36:53 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 11:45:20 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

const char	*get_op_name(uint8_t op)
{
	if (op == SA)
		return ("sa\n");
	if (op == SB)
		return ("sb\n");
	if (op == SS)
		return ("ss\n");
	if (op == PA)
		return ("pa\n");
	if (op == PB)
		return ("pb\n");
	if (op == RA)
		return ("ra\n");
	if (op == RB)
		return ("rb\n");
	if (op == RR)
		return ("rr\n");
	if (op == RRA)
		return ("rra\n");
	if (op == RRB)
		return ("rrb\n");
	if (op == RRR)
		return ("rrr\n");
	return (NULL);
}

void	exec_swap(t_stacks *stack, uint8_t op)
{
	if (op & STACK_A)
		sa(stack, 0);
	else if (op & STACK_B)
		sb(stack, 0);
}

void	exec_push(t_stacks *stack, uint8_t op)
{
	if (op & STACK_A)
		pa(stack, 0);
	else if (op & STACK_B)
		pb(stack, 0);
}

void	exec_rotate(t_stacks *stack, uint8_t op)
{
	if ((op & STACK_BOTH) == STACK_BOTH)
		rr(stack, 0);
	else if (op & STACK_A)
		ra(stack, 0);
	else if (op & STACK_B)
		rb(stack, 0);
}

void	exec_rrotate(t_stacks *stack, uint8_t op)
{
	if ((op & STACK_BOTH) == STACK_BOTH)
		rrr(stack, 0);
	else if (op & STACK_A)
		rra(stack, 0);
	else if (op & STACK_B)
		rrb(stack, 0);
}
