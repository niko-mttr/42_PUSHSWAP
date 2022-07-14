/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:40:46 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/14 10:58:29 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_count_index(int value, int index, t_list *stack)
{
	while (stack)
	{
		if (value > stack->value)
			index++;
		stack = stack->next;
	}
	return (index);
}

int	ft_middle(int size_stack, int pos)
{
	int	trigger;

	trigger = 1;
	if (size_stack == 1)
		return (0);
	if (pos > size_stack / 2)
		trigger = -1;
	return (trigger);
}

int	ft_calc_cost(int size_stack, int pos, int trigger)
{
	int	cost;

	if (trigger > 0)
		cost = pos - 1;
	else
		cost = size_stack - pos + 1;
	return (cost * trigger);
}

int	abs(int number)
{
	if (number < 0)
		number *= -1;
	return (number);
}

t_list	*ft_choose_stack(t_list *sk)
{
	t_list	*el;

	el = sk;
	while (sk)
	{
		if (abs(sk->cost_a) + abs(sk->cost_b) < abs(el->cost_a)
			+ abs(el->cost_b))
			el = sk;
		sk = sk->next;
	}
	return (el);
}
