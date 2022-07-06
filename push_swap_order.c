/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:42:02 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/06 12:32:00 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
