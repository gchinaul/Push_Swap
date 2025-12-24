/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:55:40 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 15:18:05 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	atoi_init(t_atoi *a, const char *str, int *error)
{
	a->result = 0;
	a->sign = 1;
	a->i = 0;
	*error = 0;
	while (str[a->i] == ' ' || (str[a->i] >= 9 && str[a->i] <= 13))
		a->i++;
	if (str[a->i] == '-' || str[a->i] == '+')
	{
		if (str[a->i] == '-')
			a->sign = -1;
		a->i++;
	}
}

int	ft_atoi_safe(const char *str, int *error)
{
	t_atoi	a;

	atoi_init(&a, str, error);
	if (str[a.i] < '0' || str[a.i] > '9')
		return (*error = 1, 0);
	while (str[a.i] >= '0' && str[a.i] <= '9')
		a.result = a.result * 10 + (str[a.i++] - '0');
	if (str[a.i] != '\0' || a.result * a.sign > INT_MAX || a.result
		* a.sign < INT_MIN)
		return (*error = 1, 0);
	return (a.result * a.sign);
}

void	check_duplicates(t_stacks *stacks, t_node *stack)
{
	t_node	*current;
	t_node	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				error_exit(stacks);
			checker = checker->next;
		}
		current = current->next;
	}
}

int	parse_and_add(t_stacks *stacks, char *str)
{
	int		error;
	int		value;
	t_node	*new;

	error = 0;
	value = ft_atoi_safe(str, &error);
	if (error)
		return (1);
	new = create_node(value);
	if (!new)
		return (1);
	add_node_back(&stacks->a, new);
	return (0);
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
