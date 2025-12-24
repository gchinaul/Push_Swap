/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:30:56 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 11:51:21 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	execute_op(t_stacks *stacks, uint8_t op, bool print)
{
	const uint8_t	op_type = op & 0x0F;
	const char		*name = get_op_name(op);
	size_t			len;

	if (op_type == OP_SWAP)
		exec_swap(stacks, op);
	else if (op_type == OP_PUSH)
		exec_push(stacks, op);
	else if (op_type == OP_ROTATE)
		exec_rotate(stacks, op);
	else if (op_type == OP_RROTATE)
		exec_rrotate(stacks, op);
	if (print)
	{
		if (name)
		{
			if (name[2] == '\n')
				len = 3;
			else
				len = 4;
			write(1, name, len);
		}
	}
}
