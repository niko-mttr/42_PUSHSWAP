/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:22:23 by nmattera          #+#    #+#             */
/*   Updated: 2022/07/06 14:28:42 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_repeat_reverse(t_list **stack_a, t_list **stack_b, t_list *element,
		char *action)
{
	while (!ft_strcmp(action, "RRR") && (element->cost_a != 0
			|| element->cost_b != 0))
	{
		ft_call_action(stack_a, stack_b, action);
		element->cost_a++;
		element->cost_b++;
	}
	while (!ft_strcmp(action, "RRA") && element->cost_a != 0)
	{
		ft_call_action(stack_a, stack_b, action);
		element->cost_a++;
	}
	while (!ft_strcmp(action, "RRB") && element->cost_b != 0)
	{
		ft_call_action(stack_a, stack_b, action);
		element->cost_b++;
	}
}

void	ft_repeat_rotate(t_list **stack_a, t_list **stack_b, t_list *element,
		char *action)
{
	while (!ft_strcmp(action, "RR") && (element->cost_a != 0
			|| element->cost_b != 0))
	{
		ft_call_action(stack_a, stack_b, action);
		element->cost_a--;
		element->cost_b--;
	}
	while (!ft_strcmp(action, "RA") && element->cost_a != 0)
	{
		ft_call_action(stack_a, stack_b, action);
		element->cost_a--;
	}
	while (!ft_strcmp(action, "RB") && element->cost_b != 0)
	{
		ft_call_action(stack_a, stack_b, action);
		element->cost_b--;
	}
}

void	ft_do_action(t_list **stack_a, t_list **stack_b, t_list *element)
{
	if (element->cost_a > 0 && element->cost_b > 0)
		ft_repeat_rotate(stack_a, stack_b, element, "RR");
	if (element->cost_a < 0 && element->cost_b < 0)
		ft_repeat_reverse(stack_a, stack_b, element, "RRR");
	if (element->cost_a > 0)
		ft_repeat_rotate(stack_a, stack_b, element, "RA");
	if (element->cost_b > 0)
		ft_repeat_rotate(stack_a, stack_b, element, "RB");
	if (element->cost_a < 0)
		ft_repeat_reverse(stack_a, stack_b, element, "RRA");
	if (element->cost_b < 0)
		ft_repeat_reverse(stack_a, stack_b, element, "RRB");
}

void	ft_filter(t_list **stack_a, t_list **stack_b, int size_list)
{
	int	count;
	int	mediane;
	int	size_list_b;

	count = 0;
	mediane = size_list / 2;
	size_list_b = size_list - 3;
	while (count < size_list_b)
	{
		while (size_list > mediane + 1 && count < size_list_b - 1)
		{
			if ((*stack_a)->index <= mediane)
			{
				count++;
				size_list--;
				ft_call_action(stack_a, stack_b, "PB");
			}
			else
				ft_call_action(stack_a, stack_b, "RA");
		}
		ft_call_action(stack_a, stack_b, "PB");
		count++;
	}
}

void	ft_more(t_list **stack_a, t_list **stack_b, int size_list)
{
	int	size_list_b;

	size_list_b = size_list - 3;
	ft_filter(stack_a, stack_b, size_list);
	ft_three(stack_a);
	while (size_list_b)
	{
		ft_position(*stack_b);
		ft_position(*stack_a);
		ft_target(*stack_a, *stack_b);
		ft_cost(*stack_a, *stack_b);
		ft_do_action(stack_a, stack_b, ft_choose_stack(*stack_b));
		ft_call_action(stack_a, stack_b, "PA");
		size_list_b--;
	}
	ft_finish(stack_a);
}
