/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:22:23 by nmattera          #+#    #+#             */
/*   Updated: 2022/07/05 20:22:51 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	*ft_repeatReverse(t_list **stack_a, t_list **stack_b, t_list *element,
		char *action)
{
	while (!ft_strcmp(action, "RRR") && (element->cost_a != 0 || element->cost_b != 0))
	{
		ft_callAction(stack_a, stack_b, action);
		element->cost_a++;
		element->cost_b++;
	}
	while (!ft_strcmp(action, "RRA") && element->cost_a != 0)
	{
		ft_callAction(stack_a, stack_b, action);
		element->cost_a++;
	}
	while (!ft_strcmp(action, "RRB") && element->cost_b != 0)
	{
		ft_callAction(stack_a, stack_b, action);
		element->cost_b++;
	}
}

void	*ft_repeatRotate(t_list **stack_a, t_list **stack_b, t_list *element,
		char *action)
{
	while (!ft_strcmp(action, "RR")&& (element->cost_a != 0 || element->cost_b != 0))
	{
		ft_callAction(stack_a, stack_b, action);
		element->cost_a--;
		element->cost_b--;
	}
	while (!ft_strcmp(action, "RA")&& element->cost_a != 0)
	{
		ft_callAction(stack_a, stack_b, action);
		element->cost_a--;
	}
	while (!ft_strcmp(action, "RB")&& element->cost_b != 0)
	{
		ft_callAction(stack_a, stack_b, action);
		element->cost_b--;
	}
}

void ft_doAction(t_list **stack_a, t_list **stack_b, t_list *element)
{
	if (element->cost_a > 0 && element->cost_b > 0)
		ft_repeatRotate(stack_a, stack_b, element, "RR");
	if (element->cost_a < 0 && element->cost_b < 0)
		ft_repeatReverse(stack_a, stack_b, element, "RRR");
	if (element->cost_a > 0)
		ft_repeatRotate(stack_a, stack_b, element, "RA");
	if (element->cost_b > 0)
		ft_repeatRotate(stack_a, stack_b, element, "RB");
	if (element->cost_a < 0)
		ft_repeatReverse(stack_a, stack_b, element, "RRA");
	if (element->cost_b < 0)
		ft_repeatReverse(stack_a, stack_b, element, "RRB");
}

void	ft_more(t_list **stack_a, t_list **stack_b, int sizeList)
{
	int	mediane;
	int sizeList_b;
	int	count;

	count = 0;
	mediane = sizeList / 2;
	sizeList_b = sizeList - 3;
	printf("\nsizeList : %d\n", sizeList);
	printf("ma mediane : %d\n", mediane);
	// ft_callAction(stack_a, stack_b, "RA");
	while (count < sizeList_b)
	{
		while (sizeList > mediane + 1 && count < sizeList_b -1)
		{
			if ((*stack_a)->index <= mediane)
			{
				count++;
				sizeList--;
				ft_callAction(stack_a, stack_b, "PB");
			}
			else
				ft_callAction(stack_a, stack_b, "RA");
		}		
		ft_callAction(stack_a, stack_b, "PB");
		count++;
	}
	ft_three(stack_a);
	int test;
	test = 2;
	while(test)
	{
		ft_position(*stack_b);
		ft_position(*stack_a);
		ft_space(*stack_a, *stack_b, sizeList + 3);
		ft_cost(*stack_a, *stack_b);
		ft_doAction(stack_a, stack_b, ft_chooseStack(*stack_b));
		ft_callAction(stack_a, stack_b, "PA");
		sizeList_b--;
		test--;
	}
	// while(!ft_checkOrder(*stack_a))
	// 	ft_callAction(stack_a, stack_b, "RA");
}