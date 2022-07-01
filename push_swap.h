/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:58:36 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/01 19:05:45 by nicolasmatt      ###   ########.fr       */
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
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list  *ft_lstNewNumber(int  number, int pos);

/* ****** push_swap_infos ****** */
void	ft_index(t_list *stack, int sizeList);
int 	ft_countIndex(int value, int index, t_list *stack);

/* ****** push_swap_actions ****** */
static void	rotate(t_list **stack);
void	do_ra(t_list **stack_a);
void	do_rb(t_list **stack_b);
void	do_rr(t_list **stack_a, t_list **stack_b);
t_list	*get_list_bottom(t_list *stack);
void    ft_rotateA(t_list **stack);

#endif