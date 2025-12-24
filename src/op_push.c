/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:47:55 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 11:48:06 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_node **src, t_node **dst)
{
	t_node	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

void	pa(t_stacks *stacks, int print)
{
	push(&stacks->b, &stacks->a);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks, int print)
{
	push(&stacks->a, &stacks->b);
	if (print)
		write(1, "pb\n", 3);
}
