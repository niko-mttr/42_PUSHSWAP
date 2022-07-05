/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:22:23 by nmattera          #+#    #+#             */
/*   Updated: 2022/07/05 14:44:59 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	while(sizeList_b)
	{
		ft_position(*stack_b);
		ft_space(*stack_a, *stack_b, sizeList + 3);
		ft_cost(*stack_a, *stack_b);
		ft_doAction(ft_chooseStack(*stack_b));
		sizeList_b--; 
	}
	//trier la stack_a pour qu'elle soit dans le bon ordre avec RA et RRA
}