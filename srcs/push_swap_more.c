/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:22:23 by nmattera          #+#    #+#             */
/*   Updated: 2022/07/15 13:13:58 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_repeat_reverse(t_list **stack_a, t_list **stack_b, t_list *element,
		char *action)
{
	while (!ft_strcmp(action, "rrr") && (element->cost_a != 0
			|| element->cost_b != 0))
	{
		ft_call_action(stack_a, stack_b, action);
		element->cost_a++;
		element->cost_b++;
	}
	while (!ft_strcmp(action, "rra") && element->cost_a != 0)
	{
		ft_call_action(stack_a, stack_b, action);
		element->cost_a++;
	}
	while (!ft_strcmp(action, "rrb") && element->cost_b != 0)
	{
		ft_call_action(stack_a, stack_b, action);
		element->cost_b++;
	}
}

void	ft_repeat_rotate(t_list **stack_a, t_list **stack_b, t_list *element,
		char *action)
{
	while (!ft_strcmp(action, "rr") && (element->cost_a != 0
			|| element->cost_b != 0))
	{
		ft_call_action(stack_a, stack_b, action);
		element->cost_a--;
		element->cost_b--;
	}
	while (!ft_strcmp(action, "ra") && element->cost_a != 0)
	{
		ft_call_action(stack_a, stack_b, action);
		element->cost_a--;
	}
	while (!ft_strcmp(action, "rb") && element->cost_b != 0)
	{
		ft_call_action(stack_a, stack_b, action);
		element->cost_b--;
	}
}

void	ft_do_action(t_list **stack_a, t_list **stack_b, t_list *element)
{
	if (element->cost_a > 0 && element->cost_b > 0)
		ft_repeat_rotate(stack_a, stack_b, element, "rr");
	if (element->cost_a < 0 && element->cost_b < 0)
		ft_repeat_reverse(stack_a, stack_b, element, "rrr");
	if (element->cost_a > 0)
		ft_repeat_rotate(stack_a, stack_b, element, "ra");
	if (element->cost_b > 0)
		ft_repeat_rotate(stack_a, stack_b, element, "rb");
	if (element->cost_a < 0)
		ft_repeat_reverse(stack_a, stack_b, element, "rra");
	if (element->cost_b < 0)
		ft_repeat_reverse(stack_a, stack_b, element, "rrb");
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
				ft_call_action(stack_a, stack_b, "pb");
			}
			else
				ft_call_action(stack_a, stack_b, "ra");
		}
		ft_call_action(stack_a, stack_b, "pb");
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
		ft_call_action(stack_a, stack_b, "pa");
		size_list_b--;
	}
	ft_finish(stack_a);
}
