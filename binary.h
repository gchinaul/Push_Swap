/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:06:49 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 13:42:45 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_H
# define BINARY_H

# define FLAG_ROTATE_UP 0x01
# define FLAG_ROTATE_DOWN 0x02
# define FLAG_SAME_DIR 0x04
# define FLAG_OPTIMIZABLE 0x08
# define FLAG_ROTATE_UP_A 0x10
# define FLAG_ROTATE_DOWN_A 0x20

typedef enum e_binary
{
	OP_SWAP = 0x01,
	OP_PUSH = 0x02,
	OP_ROTATE = 0x04,
	OP_RROTATE = 0x08,
	STACK_A = 0x10,
	STACK_B = 0x20,
	STACK_BOTH = (STACK_A | STACK_B),
	SA = (OP_SWAP | STACK_A),
	SB = (OP_SWAP | STACK_B),
	SS = (OP_SWAP | STACK_BOTH),
	PA = (OP_PUSH | STACK_A),
	PB = (OP_PUSH | STACK_B),
	RA = (OP_ROTATE | STACK_A),
	RB = (OP_ROTATE | STACK_B),
	RR = (OP_ROTATE | STACK_BOTH),
	RRA = (OP_RROTATE | STACK_A),
	RRB = (OP_RROTATE | STACK_B),
	RRR = (OP_RROTATE | STACK_BOTH)
}	t_op;

#endif