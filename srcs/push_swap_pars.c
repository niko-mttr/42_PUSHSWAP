/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:06:38 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/11 16:47:22 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_compare(t_list *stack)
{
	t_list	*cmp;

	cmp = stack;
	while(stack)
	{
		while(cmp)
		{
			if (cmp->value == stack->value)
				return (0);
			cmp = cmp->next;
		}
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
