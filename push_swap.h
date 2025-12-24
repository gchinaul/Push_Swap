/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:39:31 by gchinaul          #+#    #+#             */
/*   Updated: 2025/12/09 15:18:32 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "binary.h"
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int32_t			value;
	uint16_t		index;
	uint16_t		cost_a;
	uint16_t		cost_b;
	uint16_t		total_cost;
	uint8_t			flags;
	struct s_node	*target;
	struct s_node	*next;
}					t_node;

typedef struct s_stacks
{
	t_node			*a;
	t_node			*b;
	uint16_t		size_a;
	uint16_t		size_b;
}					t_stacks;

typedef struct s_atoi
{
	long			result;
	int				sign;
	int				i;
}					t_atoi;

/*-------------------------------PARSING--------------------------------------*/
int					ft_atoi_safe(const char *str, int *error);
char				**ft_split(char const *s, char c);
void				free_split(char **split);
void				init_stack(t_stacks *stacks, int argc, char **argv);
void				check_duplicates(t_stacks *stacks, t_node *stack);
int					is_sorted(t_node *stack);
int					parse_and_add(t_stacks *stacks, char *str);
/*-------------------------------GESTION--------------------------------------*/
t_node				*create_node(int value);
void				add_node_back(t_node **stack, t_node *new);
int					stack_size(t_node *stack);
t_node				*get_last_node(t_node *stack);
void				free_stack(t_node **stack);
/*-------------------------------OPERATION------------------------------------*/
const char			*get_op_name(uint8_t op);
void				execute_op(t_stacks *stacks, uint8_t op, bool print);
void				exec_swap(t_stacks *stack, uint8_t op);
void				sa(t_stacks *stacks, int print);
void				sb(t_stacks *stacks, int print);
void				ss(t_stacks *stacks, int print);
void				exec_push(t_stacks *stack, uint8_t op);
void				pa(t_stacks *stacks, int print);
void				pb(t_stacks *stacks, int print);
void				exec_rotate(t_stacks *stack, uint8_t op);
void				ra(t_stacks *stacks, int print);
void				rb(t_stacks *stacks, int print);
void				rr(t_stacks *stacks, int print);
void				exec_rrotate(t_stacks *stack, uint8_t op);
void				rra(t_stacks *stacks, int print);
void				rrb(t_stacks *stacks, int print);
void				rrr(t_stacks *stacks, int print);
/*-------------------------------ALGORITHM-----------------------------------*/
void				sort_three(t_stacks *stacks);
void				turk_algorithm(t_stacks *stacks);
void				assign_index(t_node *stack);
void				update_stack_sizes(t_stacks *stacks);
void				find_target_nodes(t_node *stack_a, t_node *stack_b);
void				calculate_costs(t_stacks *stacks, t_node *stack_b);
t_node				*find_cheapest_node(t_node *stack_b);
void				execute_cheapest_move(t_stacks *stacks, t_node *cheapest);
void				rotate_to_min(t_stacks *stacks);
void				bring_to_top_a(t_stacks *stacks, t_node *node);
void				bring_to_top_b(t_stacks *stacks, t_node *node);
/*-------------------------------UTILS--------------------------------------*/
void				error_exit(t_stacks *stacks);
int					ft_strcmp(const char *s, const char *s2);
uint16_t			fast_stack_size(t_node *stack);

#endif
