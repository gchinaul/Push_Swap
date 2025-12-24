/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:59:44 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 15:22:26 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_exit(t_stacks *stacks)
{
	free_stack(&stacks->a);
	free_stack(&stacks->b);
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**split_args;

	split_args = NULL;
	if (argc < 2)
		return (0);
	stacks.a = NULL;
	stacks.b = NULL;
	stacks.size_a = 0;
	stacks.size_b = 0;
	init_stack(&stacks, argc, argv);
	update_stack_sizes(&stacks);
	if (!is_sorted(stacks.a))
	{
		if (stacks.size_a == 2)
			sa(&stacks, 1);
		else if (stacks.size_a == 3)
			sort_three(&stacks);
		else
			turk_algorithm(&stacks);
	}
	free_split(split_args);
	free_stack(&stacks.a);
	free_stack(&stacks.b);
	return (0);
}
