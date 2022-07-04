/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:22:23 by nmattera          #+#    #+#             */
/*   Updated: 2022/07/04 14:49:38 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_more(t_list **stack_a, t_list **stack_b, int sizeList)
{
	int	mediane;

	mediane = sizeList / 2;
	printf("\nsizeList : %d\n", sizeList);
	printf("ma mediane : %d\n", mediane);
	while (sizeList - 3 > 0)
	{
		while (sizeList > mediane + 1)
		{
			if ((*stack_a)->index <= mediane)
			{
				sizeList--;
				ft_push(stack_a, stack_b, "PB\n");
			}
			else
				ft_rotate(stack_a, "RA\n");
		}		
		ft_push(stack_a, stack_b, "PB\n");
		sizeList--;
	}
	ft_three(stack_a);
	// while(*stack_b/*des nombres dans la stack_b*/)
	// {
		// ft_position(stack_b);
		//calculer la position cible dans la pile A
		//calculer le nombre d'actions(choisir l'element le moins couteux)
		//push(stack_b, stack_a, "PA\n");
	// }
	//trier la stack_a pour qu'elle soit dans le bon ordre avec RA et RRA
}