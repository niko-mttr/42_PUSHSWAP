/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:31:47 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/16 20:45:02 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

t_list	*ft_fill_stack(int size_list, char **list, int split)
{
	int		pos;
	int		number;
	t_list	*stack;
	t_list	*tmp;

	stack = NULL;
	pos = 0;
	while (pos < size_list)
	{
		number = ft_atoi(list[pos], &stack, split, list);
		if (pos == 0)
			stack = ft_lst_new_number(number);
		else
		{
			tmp = ft_lst_new_number(number);
			if (!tmp)
				ft_malloc_error(stack, list, split);
			ft_lstadd_back(&stack, tmp);
		}
		pos++;
	}
	return (stack);
}

int	ft_ex_number(int size_list, char **list, int split)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = ft_fill_stack(size_list, list, split);
	ft_index(stack_a, size_list);
	ft_position(stack_a);
	if (!ft_compare(stack_a))
	{
		ft_putstr_fd("Error", 1);
		ft_end(split, &stack_a, list);
		return (EXIT_FAILURE);
	}
	if (!ft_check_order(stack_a))
	{
		if (size_list == 2)
			ft_swap(&stack_a, "sa");
		else if (size_list == 3)
			ft_three(&stack_a);
		else if (size_list > 3)
			ft_more(&stack_a, &stack_b, size_list);
	}
	ft_end(split, &stack_a, list);
	return (EXIT_SUCCESS);
}

int	first_pars(int argc, char **argv, int *split, char ***list)
{
	if (argc == 1)
		return (0);
	*split = 0;
	if (argc == 2 && argv[1][0] != 0)
	{
		*split = 1;
		*list = ft_split(argv[1], ' ');
		if (!list)
			return (0);
	}
	if (argc > 2)
	{
		argv++;
		*list = argv;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	**list;
	int		size_list;
	int		split;
	size_t	i;

	if (!first_pars(argc, argv, &split, &list))
		return (EXIT_FAILURE);
	size_list = 0;
	while (list[size_list])
		size_list++;
	if (ft_pars_number(size_list, list))
		return (ft_ex_number(size_list, list, split));
	if (split == 1)
	{
		i = 0;
		while (list[i])
		{
			free(list[i]);
			i++;
		}
		free(list);
	}
	return (EXIT_FAILURE);
}
