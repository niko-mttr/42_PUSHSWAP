/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:25:37 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/03 20:41:35 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_countIndex(int value, int index, t_list *stack)
{
	// printf("la valeur : %d, l'index : %d || la valeur du maillon : %d\n", value, index, stack->value);
	while (stack)
	{
		if (value > stack->value)
			index++;
		stack = stack->next; 
	}
	return (index);
}

void	ft_index(t_list *stack, int sizeList)
{
	int		nb;
	t_list	*temp;
	int		index;

	temp = stack;
	while (sizeList > 1)
	{
		index = 1;
		index = ft_countIndex(temp->value, index, stack);
		sizeList--;
		temp->index = index;
		temp = temp->next;
	}
}

void	ft_position(t_list **stack)
{
	int	pos;

	pos = 1;
	while ((*stack))
	{
		(*stack)->pos = pos;
		(*stack) = (*stack)->next;
		pos++;
	}
}

/* ******************************************************** */
// void	do_ra(t_list **stack_a)
// {
// 	rotate(stack_a);
// 	// ft_putstr("ra\n");
// }

// void	do_rb(t_list **stack_b)
// {
// 	rotate(stack_b);
// 	ft_putstr_fd("rb\n", 1);
// }

// void	do_rr(t_list **stack_a, t_list **stack_b)
// {
// 	rotate(stack_a);
// 	rotate(stack_b);
// 	ft_putstr_fd("rr\n", 1);
// }
