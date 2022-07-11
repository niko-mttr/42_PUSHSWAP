/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:31:47 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/11 16:47:29 by nicolasmatt      ###   ########.fr       */
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

int	ft_ex_number(int size_list, char **list)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = malloc(sizeof(*stack_b));
	if (!stack_b)
		return (0);
	stack_b = NULL;
	stack_a = ft_fill_stack(size_list, list);
	if(!ft_compare(stack_a))
	{
		// ft_free(stack_a);
		return (0);
	}
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
	return (1);
}

int	main(int argc, char **argv)
{
	char	**list;
	int		size_list;

	if (argc == 0 || argc == 1)
		return (0);
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		if (!list)
			// ft_exit();
			return (0);
	}
	else
		list = ++argv;
	size_list = 0;
	while (list[size_list])
		size_list++;
	if (ft_pars_number(size_list, list))
		ft_ex_number(size_list, list);
	free(list);
			//ft_exNUMBER renvoie 1 si ça s'sts bien passé 
				// si c'est 1 ça veut dire qu'il n'y a pas de doublon et qu'on peut commencer le tri dans un void
			//si c'est 0 on ne fait pas le tri et on passe par exit avant le return pour tout free correctement
}
