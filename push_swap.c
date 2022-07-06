/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:31:47 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/06 14:21:31 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*ft_lst_new_number(int number)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = number;
	new->index = 0;
	new->pos = 1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

t_list	*ft_fill_stack(int size_list, char **list)
{
	int		pos;
	int		number;
	t_list	*stack;

	stack = NULL;
	pos = 1;
	while (pos < size_list)
	{
		number = ft_atoi(list[pos]);
		if (pos == 1)
			stack = ft_lst_new_number(number);
		else
			ft_lstadd_back(&stack, ft_lst_new_number(number));
		pos++;
	}
	return (stack);
}

void	ft_ex_number(int size_list, char **list)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = malloc(sizeof(*stack_b));
	stack_b = NULL;
	stack_a = ft_fill_stack(size_list, list);
	ft_index(stack_a, size_list);
	ft_position(stack_a);
	if (!ft_check_order(stack_a))
	{
		if (size_list - 1 == 2)
			ft_swap(&stack_a, "SA");
		else if (size_list - 1 == 3)
			ft_three(&stack_a);
		else if (size_list - 1 > 3)
			ft_more(&stack_a, &stack_b, size_list - 1);
	}
	ft_checkex(stack_a, "-----stack_a-----\n");
	ft_checkex(stack_b, "-----stack_b-----\n");
}

int	main(int argc, char **argv)
{
	if (argc == 0 || argc == 1)
		return (0);
	if (ft_pars_number(argc, argv))
		ft_ex_number(argc, argv);
}
