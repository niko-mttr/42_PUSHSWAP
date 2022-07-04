/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:22:23 by nmattera          #+#    #+#             */
/*   Updated: 2022/07/04 18:13:52 by nmattera         ###   ########.fr       */
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
				ft_push(stack_a, stack_b, "PB\n");
			}
			else
				ft_rotate(stack_a, "RA\n");
		}		
		ft_push(stack_a, stack_b, "PB\n");
		count++;
	}
	ft_three(stack_a);
	while(sizeList_b)
	{
		ft_position(*stack_b);
		ft_space(*stack_a, *stack_b, sizeList + 3);
		//calculer le nombre d'actions(choisir l'element le moins couteux)
		//push(stack_b, stack_a, "PA\n");
		sizeList_b--; 
	}
	//trier la stack_a pour qu'elle soit dans le bon ordre avec RA et RRA
}