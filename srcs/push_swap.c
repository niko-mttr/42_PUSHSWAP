/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:31:47 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/14 11:48:53 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
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
	pos = 0;
	while (pos < size_list)
	{
		number = ft_atoi(list[pos], &stack);
		if (pos == 0)
			stack = ft_lst_new_number(number);
		else
			ft_lstadd_back(&stack, ft_lst_new_number(number));
		pos++;
	}
	return (stack);
}

int	ft_ex_number(int size_list, char **list)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = malloc(sizeof(*stack_b));
	if (!stack_b)
		return (0);
	stack_b = NULL;
	stack_a = ft_fill_stack(size_list, list);
	ft_index(stack_a, size_list);
	ft_position(stack_a);
	if(!ft_compare(stack_a))
	{
		printf("EGALITE\n");
		// ft_free(stack_a);
		return (0);
	}
	if (!ft_check_order(stack_a))
	{
		if (size_list == 2)
			ft_swap(&stack_a, "SA");
		else if (size_list == 3)
			ft_three(&stack_a);
		else if (size_list > 3)
			ft_more(&stack_a, &stack_b, size_list);
		ft_checkex(stack_a, "-----stack_a-----\n");
		ft_checkex(stack_b, "-----stack_b-----\n");
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	**list;
	int		size_list;
	int		split;

	if (argc == 1)
		return (0);
	split = 0;
	if (argc == 2)
	{
		split = 1;
		list = ft_split(argv[1], ' ');
		if (!list)
			// ft_exit();
			return (0);
	}
	else
	{
		argv++;
		list = argv;
	}
	size_list = 0;
	while (list[size_list])
		size_list++;
	if (ft_pars_number(size_list, list))
		ft_ex_number(size_list, list);
	if (split)
		free(list);
}

/* ****** RESTE A FAIRE ****** */
// free
// norminette 
// cosignes de retour