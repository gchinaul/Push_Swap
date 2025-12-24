/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:04:22 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 15:17:44 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_exit(t_stacks *stacks)
{
	write(2, "Error\n", 6);
	free_stack(&stacks->a);
	free_stack(&stacks->b);
	exit(EXIT_FAILURE);
}

static char	*gnl(void)
{
	char	*line;
	char	buff;
	int		i;
	int		read_ret;

	line = malloc(sizeof(char) * 1000);
	if (!line)
		return (NULL);
	i = 0;
	read_ret = read(0, &buff, 1);
	while (read_ret > 0 && buff != '\n')
	{
		line[i++] = buff;
		read_ret = read(0, &buff, 1);
	}
	line[i] = '\0';
	if (read_ret <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static void	exec(t_stacks *stacks, char *inst)
{
	if (ft_strcmp(inst, "sa") == 0)
		sa(stacks, 0);
	else if (ft_strcmp(inst, "sb") == 0)
		sb(stacks, 0);
	else if (ft_strcmp(inst, "ss") == 0)
		ss(stacks, 0);
	else if (ft_strcmp(inst, "pa") == 0)
		pa(stacks, 0);
	else if (ft_strcmp(inst, "pb") == 0)
		pb(stacks, 0);
	else if (ft_strcmp(inst, "ra") == 0)
		ra(stacks, 0);
	else if (ft_strcmp(inst, "rb") == 0)
		rb(stacks, 0);
	else if (ft_strcmp(inst, "rr") == 0)
		rr(stacks, 0);
	else if (ft_strcmp(inst, "rra") == 0)
		rra(stacks, 0);
	else if (ft_strcmp(inst, "rrb") == 0)
		rrb(stacks, 0);
	else if (ft_strcmp(inst, "rrr") == 0)
		rrr(stacks, 0);
	else
		error_exit(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		*inst;

	if (argc < 2)
		return (0);
	stacks.a = NULL;
	stacks.b = NULL;
	init_stack(&stacks, argc, argv);
	inst = gnl();
	while (inst)
	{
		if (inst[0] != '\0')
			exec(&stacks, inst);
		free(inst);
		inst = gnl();
	}
	if (is_sorted(stacks.a) && !stacks.b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stacks.a);
	free_stack(&stacks.b);
	return (0);
}
