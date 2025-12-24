/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:23:08 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 15:23:18 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	update_stack_sizes(t_stacks *stacks)
{
	stacks->size_a = fast_stack_size(stacks->a);
	stacks->size_b = fast_stack_size(stacks->b);
}
