/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checkex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:16:31 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/08 15:30:08 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void ft_checkex(t_list *chaine, char *name)
{
    printf("%s", name);
    while (chaine)
    {
        printf("%d || pos : %d || index : %d || taregt_pos : %d || cost_a : %d || cost_b : %d\n",
        chaine->value, chaine->pos, chaine->index, chaine->target_pos, chaine->cost_a, chaine->cost_b);
        chaine = chaine->next;
    }
    printf("\n");
}