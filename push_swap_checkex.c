/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checkex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:16:31 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/05 13:30:39 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void ft_checkex(t_list *chaine, char *name)
{
    printf("%s", name);
    while (chaine)
    {
        printf("%d || pos : %d || index : %d || taregt_pos : %d\n", chaine->value, chaine->pos, chaine->index, chaine->target_pos);
        chaine = chaine->next;
    }
    printf("\n");
}