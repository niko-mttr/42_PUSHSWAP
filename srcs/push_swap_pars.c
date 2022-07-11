/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:06:38 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/11 12:32:35 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	ft_doublon(int sizeList, char **list, int check)
{
	int	index;
	int	level;

	index = 1;
	while (index < sizeList && check)
	{
		level = 1;
		while (level < sizeList && check)
		{
			if (!ft_strcmp(list[index], list[level]) && index != level)
				check = 0;
			level++;
		}
		index++;
	}
	return (check);
}

int	ft_pars_number(int sizeList, char **list)
{
	int	index;
	int	check;
	int	i;

	check = 1;
	index = 1;
	if (sizeList == 2)
	{
		if (ft_check_string(list[1]))
			list = ft_split(list[1], ' ');
		else
			check = 0;
	}
	else
	{
		while (index < sizeList && check == 1)
		{
			i = 0;
			while (list[index][i])
			{	
				if (!ft_isdigit(list[index][i]))
					check = 0;
				i++;	
			}
			index++;
		}
	}
	if (check == 1)
		check = ft_doublon(sizeList, list, check);
	else
		ft_putstr_fd("Error", 1);
	return (check);
}
