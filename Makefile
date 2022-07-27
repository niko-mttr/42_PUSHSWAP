# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 15:23:20 by nicolasmatt       #+#    #+#              #
#    Updated: 2022/07/27 11:42:47 by nmattera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = pushswap_bonus

SRCS = srcs/push_swap_actions.c srcs/push_swap_finish.c srcs/push_swap_infos.c srcs/push_swap_more.c srcs/push_swap_order.c srcs/push_swap_pars.c srcs/push_swap_value.c srcs/push_swap_stack.c srcs/push_swap_three.c srcs/push_swap_utils.c srcs/push_swap.c srcs/push_swap_exit.c

OBJS = ${SRCS:.c=.o}

cc = cc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = -I libft -I includes

.c.o: @${CC} ${CFLAGS} ${INCLUDES} -c -o $@ $<

all: ${NAME}

${NAME}: ${OBJS}
	@echo "----Compiling lib----"
	@make re -C libft --no-print-directory
	@$(CC) $(CFLAGS) ${OBJS} -Llibft -lft ${INCLUDES} -o ${NAME}
	@echo "Push Swap Compiled!"

clean:
	@make clean -C libft --no-print-directory
	@rm -f ${OBJS}
	@rm -f ${OBJSB}

fclean: clean
	@make fclean -C libft
	@rm -f ${NAME}
	@rm -f $(NAME_BONUS)
	@echo "Deleting EVERYTHING!\n"

re: fclean all

bonus: ${NAME_BONUS}

re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus bonus