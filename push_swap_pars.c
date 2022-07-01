/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:06:38 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/06/30 15:10:03 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int ft_doublon(int sizeList, char **list, int check)
{
    int index;
    int level;

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
    return check;
}

int ft_is_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int ft_parsNumber(int   sizeList, char **list)
{
    int index;
    int check;
    int i;

    check = 1;
    index = 1;
    i = 0;
    while (index < sizeList && check == 1)
    {
        while (list[index][i])
        {
            if (!ft_is_num(list[index][i]))
                check = 0;
            i++;
        }
        index++;
    }
    if (check == 1)
        check = ft_doublon(sizeList, list, check);
    //est ce qu'il faut trier INT MAX et INT MIN ??
    return check;
}