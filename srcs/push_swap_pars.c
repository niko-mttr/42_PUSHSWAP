/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:06:38 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/14 18:53:20 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_doublon(t_list *cmp, int value, int pos)
{
	while (cmp)
	{
		if (cmp->value == value && cmp->pos != pos)
			return (0);
		cmp = cmp->next;
	}
	return (1);
}

int	ft_compare(t_list *stack)
{
	t_list	*cmp;

	cmp = stack;
	while (stack)
	{
		if (!ft_doublon(cmp, stack->value, stack->pos))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_pars_number(int sizeList, char **list)
{
	int	index;
	int	check;
	int	i;

	check = 1;
	index = 0;
	while (index < sizeList && check == 1)
	{
		i = 0;
		if (list[index][i] == 0 && i == 0)
			check = 0;
		if (list[index][i] == '+' || list[index][i] == '-')
			i++;
		while (list[index][i])
		{
			if (!ft_isdigit(list[index][i]))
				check = 0;
			i++;
		}
		index++;
	}
	if (check != 1)
		ft_putstr_fd("Error", 1);
	return (check);
}
