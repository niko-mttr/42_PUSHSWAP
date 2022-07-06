/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:58:36 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/06 13:14:45 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	void			*content;
	struct s_list	*next;
}					t_list;

/* ****** push_swap.c ****** */
t_list				*ft_lst_new_number(int number, int pos);
t_list				*ft_fill_stack(int size_list, char **list);
void				ft_ex_number(int size_list, char **list);
int					main(int argc, char **argv);

/* ******* push_swap_pars ****** */
int					ft_pars_number(int sizeList, char **list);
int					ft_doublon(int sizeList, char **list, int check);
int					ft_strcmp(char *s1, char *s2);

/* ******* push_swap_checkex ******* */
void				ft_checkex(t_list *chaine, char *name);

/* ******* push_swap_stack ****** */
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstbeforelast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);

/* ****** push_swap_infos ****** */
void				ft_index(t_list *stack, int size_list);
void				ft_position(t_list *stack);
void				ft_target(t_list *stack_a, t_list *stack_b);
void				ft_cost(t_list *stack_a, t_list *stack_b);

/* ****** push_swap_actions ****** */
void				ft_rotate(t_list **stack);
void				ft_reverse_rotate(t_list **stack);
void				ft_swap(t_list **stack, char *instruction);
void				ft_push(t_list **src, t_list **dest);
void				ft_call_action(t_list **stack_a, t_list **stack_b,
						char *call);

/* ****** push_swap_utils.c ****** */
int					ft_count_index(int value, int index, t_list *stack);
int					ft_middle(int size_stack, int pos);
int					ft_calc_cost(int size_stack, int pos, int trigger);
int					abs(int number);
t_list				*ft_choose_stack(t_list *sk);

/* ****** push_swap_order.c ****** */
int					ft_check_order(t_list *stack);

/* ****** push_swap_three.c ****** */
int					ft_index_max(t_list *stack, int indexRef);
int					ft_index_middle(t_list *stack, int indexRef);
void				ft_three(t_list **stack);

/* ****** push_swap_more.c ****** */
void				ft_more(t_list **stack_a, t_list **stack_b, int sizeList);
void				ft_do_action(t_list **stack_a, t_list **stack_b,
						t_list *element);
void				*ft_repeat_rotate(t_list **stack_a, t_list **stack_b,
						t_list *element, char *action);
void				*ft_repeat_reverse(t_list **stack_a, t_list **stack_b,
						t_list *element, char *action);

/* ****** push_swap_finish.c ****** */
int					ft_tallest(t_list *stack, int size_stack);
void				ft_finish(t_list **stack);

#endif