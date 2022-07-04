/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:58:36 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/04 09:44:47 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_list
{
    int     value;
    int     index;
    int     pos;
    int     target_pos;
    int     cost_a;
    int     cost_b;
    void    *content;
    struct s_list  *next;
}               t_list;

/* ******* push_swap_pars ****** */
int ft_parsNumber(int   sizeList, char **list);
int ft_is_num(char c);
int ft_doublon(int sizeList, char **list, int check);
int	ft_strcmp(char *s1, char *s2);

/* ******* push_swap_checkex ******* */
void ft_checkex(t_list *chaine);

/* ******* push_swap_stack ****** */
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstbeforelast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list  *ft_lstNewNumber(int  number, int pos);

/* ****** push_swap_infos ****** */
void	ft_index(t_list *stack, int sizeList);
int 	ft_countIndex(int value, int index, t_list *stack);
void	ft_position(t_list *stack);

/* ****** push_swap_actions ****** */
void    ft_rotate(t_list **stack, char *instruction);
void    ft_reverseRotate(t_list **stack, char *instruction);
void    ft_swap(t_list **stack, char *instruction);

/* ****** push_swap_order.c ****** */
int     ft_checkOrder(t_list *stack);

/* ****** push_swap_order.c ****** */
void    ft_three(t_list **stack);

#endif