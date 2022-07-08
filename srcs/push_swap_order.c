/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:42:02 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/08 15:30:36 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_order(t_list *stack)
{
	int	temp;

	temp = stack->value;
	while (stack)
	{
		if (temp > stack->value)
			return (0);
		temp = stack->value;
		stack = stack->next;
	}
	return (1);
}
