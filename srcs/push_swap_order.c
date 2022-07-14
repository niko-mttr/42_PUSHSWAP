/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:42:02 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/14 11:54:25 by nmattera         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	i = (*s1 - *s2);
	return (i);
}

void	ft_delstack(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(stack);
		(*stack) = tmp;
	}
	stack = NULL;
}
